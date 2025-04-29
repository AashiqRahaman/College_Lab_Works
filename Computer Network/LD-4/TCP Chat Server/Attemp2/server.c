#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8000
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// XOR encryption function
void xor_encrypt_decrypt(char *message)
{
    for (int i = 0; message[i]; i++)
    {
        message[i] ^= 39;
    }
}

// Broadcast encrypted message to all clients except sender
void broadcast(char *message, int sender_sock)
{
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_sock)
        {
            char temp[BUFFER_SIZE];
            strcpy(temp, message);
            xor_encrypt_decrypt(temp); // Encrypt before sending
            send(client_sockets[i], temp, strlen(temp), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *arg)
{
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes;

    while ((bytes = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0)
    {
        buffer[bytes] = '\0';
        printf("Received: %s", buffer);
        broadcast(buffer, sock); // Relay to others
    }

    // Remove client
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; ++i)
    {
        if (client_sockets[i] == sock)
        {
            client_sockets[i] = 0;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    close(sock);
    return NULL;
}

int main()
{
    int server_fd, new_sock;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    pthread_t tid;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, MAX_CLIENTS);
    printf("Chat server started on port %d...\n", PORT);

    while (1)
    {
        new_sock = accept(server_fd, (struct sockaddr *)&address, &addrlen);

        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; ++i)
        {
            if (client_sockets[i] == 0)
            {
                client_sockets[i] = new_sock;
                pthread_create(&tid, NULL, handle_client, &client_sockets[i]);
                break;
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    return 0;
}
