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
static unsigned int cli_count = 0;
static int uid = 10;
typedef struct
{
    struct sockaddr_in address;
    int sockfd;
    int uid;
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
void add_client(client_t *cl)
{
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (!clients[i])
        {
            clients[i] = cl;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}
void remove_client(int uid)
{
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] && clients[i]->uid == uid)
        {
            clients[i] = NULL;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}
void send_message_to_client(char *s, char *to)
{
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (clients[i] && strcmp(clients[i]->name, to) == 0)
        {
            send(clients[i]->sockfd, s, strlen(s), 0);
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}
void send_active_clients(int sockfd)
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
    send(sockfd, list, strlen(list), 0);
}
void *handle_client(void *arg)
{
    char buff_out[BUFFER_SZ];
    char name[NAME_LEN];
    int leave_flag = 0;
    cli_count++;
    client_t *cli = (client_t *)arg;
    if (recv(cli->sockfd, name, NAME_LEN, 0) <= 0 || strlen(name) < 2 || strlen(name) >= NAME_LEN - 1)
    {
        printf("Didn't enter the name.\n");
        leave_flag = 1;
    }
    else
    {
        strcpy(cli->name, name);
        sprintf(buff_out, "%s has joined\n", cli->name);
        printf("%s", buff_out);
    }
    add_client(cli);
    while (1)
    {
        if (leave_flag)
            break;
        int receive = recv(cli->sockfd, buff_out, BUFFER_SZ, 0);
        if (receive > 0)
        {
            buff_out[receive] = '\0';
            str_trim_lf(buff_out, strlen(buff_out));
            if (strncmp(buff_out, "/list", 5) == 0)
            {
                send_active_clients(cli->sockfd);
            }
            else if (strncmp(buff_out, "/msg ", 5) == 0)
            {
                char *to = strtok(buff_out + 5, " ");
                char *msg = strtok(NULL, "");
                if (to && msg)
                {
                    char formatted_msg[BUFFER_SZ];
                    sprintf(formatted_msg, "[Private] %s: %s\n", cli->name, msg);
                    send_message_to_client(formatted_msg, to);
                }
                else
                {
                    char *err = "Usage: /msg <username> <message>\n";
                    send(cli->sockfd, err, strlen(err), 0);
                }
            }
            else
            {
                char *err = "Unknown command. Use /list or /msg <username> <message>\n";
                send(cli->sockfd, err, strlen(err), 0);
            }
        }
        else
        {
            leave_flag = 1;
        }
    }
    close(cli->sockfd);
    remove_client(cli->uid);
    free(cli);
    cli_count--;
    pthread_detach(pthread_self());
    return NULL;
}
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);
    int option = 1;
    int listenfd = 0, connfd = 0;
    struct sockaddr_in serv_addr, cli_addr;
    pthread_t tid;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    if (bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR: bind");
        return EXIT_FAILURE;
    }
    if (listen(listenfd, 10) < 0)
    {
        perror("ERROR: listen");
        return EXIT_FAILURE;
    }
    printf("=== Welcome to the Secure Chat Server ===\n");
    while (1)
    {
        socklen_t clilen = sizeof(cli_addr);
        connfd = accept(listenfd, (struct sockaddr *)&cli_addr, &clilen);
        if ((cli_count + 1) == MAX_CLIENTS)
        {
            printf("Max clients reached. Rejected: %d\n", cli_addr.sin_port);
            close(connfd);
            continue;
        }
        client_t *cli = (client_t *)malloc(sizeof(client_t));
        cli->address = cli_addr;
        cli->sockfd = connfd;
        cli->uid = uid++;
        pthread_create(&tid, NULL, &handle_client, (void *)cli);
    }
    return EXIT_SUCCESS;
}
