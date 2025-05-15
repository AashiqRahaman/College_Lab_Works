#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MAX_CLIENTS 100
#define NAME_LEN 32
#define BUFFER_SZ 2048
#define CLIENTS_FILE "clients.txt"
typedef struct
{
    struct sockaddr_in address;
    char name[NAME_LEN];
} client_t;
client_t *clients[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;
void str_trim_lf(char *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == '\n')
        {
            arr[i] = '\0';
            break;
        }
    }
}
int addr_cmp(struct sockaddr_in *a, struct sockaddr_in *b)
{
    return a->sin_addr.s_addr == b->sin_addr.s_addr && a->sin_port == b->sin_port;
}
void save_clients_to_file()
{
    FILE *fp = fopen(CLIENTS_FILE, "w");
    if (!fp)
        return;
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i])
        {
            char ip[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &(clients[i]->address.sin_addr), ip, INET_ADDRSTRLEN);
            int port = ntohs(clients[i]->address.sin_port);
            fprintf(fp, "%s:%d %s\n", ip, port, clients[i]->name);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    fclose(fp);
}
void load_clients_from_file()
{
    FILE *fp = fopen(CLIENTS_FILE, "r");
    if (!fp)
        return;
    char line[BUFFER_SZ];
    while (fgets(line, sizeof(line), fp))
    {
        str_trim_lf(line, strlen(line));
        char ip[INET_ADDRSTRLEN];
        int port;
        char name[NAME_LEN];
        if (sscanf(line, "%[^:]:%d %[^\n]", ip, &port, name) == 3)
        {
            struct sockaddr_in addr;
            addr.sin_family = AF_INET;
            inet_pton(AF_INET, ip, &(addr.sin_addr));
            addr.sin_port = htons(port);
            client_t *cli = (client_t *)malloc(sizeof(client_t));
            cli->address = addr;
            strncpy(cli->name, name, NAME_LEN);
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < MAX_CLIENTS; ++i)
            {
                if (!clients[i])
                {
                    clients[i] = cli;
                    break;
                }
            }
            pthread_mutex_unlock(&clients_mutex);
        }
    }
    fclose(fp);
}
void add_or_update_client(struct sockaddr_in addr, char *name)
{
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] && addr_cmp(&clients[i]->address, &addr))
        {
            strncpy(clients[i]->name, name, NAME_LEN);
            pthread_mutex_unlock(&clients_mutex);
            save_clients_to_file();
            return;
        }
    }
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (!clients[i])
        {
            client_t *cli = (client_t *)malloc(sizeof(client_t));
            cli->address = addr;
            strncpy(cli->name, name, NAME_LEN);
            clients[i] = cli;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    save_clients_to_file();
}
void remove_client(struct sockaddr_in *addr)
{
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] && addr_cmp(&clients[i]->address, addr))
        {
            printf("%s disconnected\n", clients[i]->name);
            free(clients[i]);
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    save_clients_to_file();
}
client_t *get_client_by_address(struct sockaddr_in *addr)
{
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] && addr_cmp(&clients[i]->address, addr))
        {
            return clients[i];
        }
    }
    return NULL;
}
client_t *get_client_by_name(const char *name)
{
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] && strcmp(clients[i]->name, name) == 0)
        {
            return clients[i];
        }
    }
    return NULL;
}
void send_active_clients(int sockfd, struct sockaddr_in *cli_addr)
{
    char list[BUFFER_SZ] = "--- Active Clients ---\n";
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i])
        {
            strcat(list, clients[i]->name);
            strcat(list, "\n");
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    sendto(sockfd, list, strlen(list), 0, (struct sockaddr *)cli_addr, sizeof(*cli_addr));
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);
    int sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SZ];
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR: bind");
        return EXIT_FAILURE;
    }
    load_clients_from_file();
    printf("=== UDP Chat Server Started ===\n");
    while (1)
    {
        socklen_t clilen = sizeof(cli_addr);
        int recv_len = recvfrom(sockfd, buffer, BUFFER_SZ, 0, (struct sockaddr *)&cli_addr, &clilen);
        if (recv_len > 0)
        {
            buffer[recv_len] = '\0';
            str_trim_lf(buffer, BUFFER_SZ); // Handle exit message
            if (strcmp(buffer, "__exit__") == 0)
            {
                remove_client(&cli_addr);
                continue;
            }
            client_t *cli = get_client_by_address(&cli_addr); // New client
            if (!cli)
            {
                if (strlen(buffer) > 0)
                {
                    add_or_update_client(cli_addr, buffer);
                    printf("%s registered (new)\n", buffer);
                }
                else
                {
                    const char *prompt = "[Server] Please send your name:\n";
                    sendto(sockfd, prompt, strlen(prompt), 0, (struct sockaddr *)&cli_addr, clilen);
                }
                continue;
            }
            if (strcmp(buffer, "/list") == 0)
            {
                send_active_clients(sockfd, &cli_addr);
            }
            else if (strncmp(buffer, "/msg ", 5) == 0)
            {
                char *to = strtok(buffer + 5, " ");
                char *msg = strtok(NULL, "");
                if (to && msg)
                {
                    client_t *target = get_client_by_name(to);
                    if (target)
                    {
                        char formatted[BUFFER_SZ];
                        snprintf(formatted, BUFFER_SZ, "[Private] %s: %s\n", cli->name, msg);
                        sendto(sockfd, formatted, strlen(formatted), 0,
                               (struct sockaddr *)&target->address, sizeof(target->address));
                    }
                }
            }
            else
            {
                const char *err = "Unknown command. Use /list or /msg <username> <message>\n";
                sendto(sockfd, err, strlen(err), 0, (struct sockaddr *)&cli_addr, sizeof(cli_addr));
            }
        }
    }
    close(sockfd);
    return EXIT_SUCCESS;
}
