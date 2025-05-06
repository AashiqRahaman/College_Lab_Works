#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CLIENTS 3
#define BUFFER_SIZE 1024

struct sockaddr_in client_addrs[MAX_CLIENTS];
int client_count = 0;



// char xor_encrypt_decrypt(char *message)
// {   
//     // int n= sizeof(message);
//     char temp[BUFFER_SIZE];
//     temp= messege;
//     for (int i = 0; temp[i]; i++)
//     {
//         temp[i] ^= 39;
//     }
//     return *temp;
// }





int is_known_client(struct sockaddr_in *client) {
    for (int i = 0; i < client_count; i++) {
        if (client_addrs[i].sin_addr.s_addr == client->sin_addr.s_addr &&
            client_addrs[i].sin_port == client->sin_port) {
            return 1;
        }
    }
    return 0;
}

void add_client(struct sockaddr_in *client) {
    if (!is_known_client(client) && client_count < MAX_CLIENTS) {
        client_addrs[client_count++] = *client;
    }
}

int main() {
    int sockfd;
    char buffer[BUFFER_SIZE];
    char temp[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("UDP Chat Server started on port %d...\n", PORT);

    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0,
                         (struct sockaddr *)&client_addr, &addr_len);
        buffer[n] = '\0';

        add_client(&client_addr);




        temp = xor_encrypt_decrypt(buffer);
        printf("Received: %s", buffer);  // Show received message

        // Broadcast to all clients except sender
        for (int i = 0; i < client_count; i++) {
            if (client_addrs[i].sin_addr.s_addr != client_addr.sin_addr.s_addr ||
                client_addrs[i].sin_port != client_addr.sin_port) {
                sendto(sockfd, buffer, n, 0,
                       (struct sockaddr *)&client_addrs[i], sizeof(client_addrs[i]));
            }
        }
    }

    close(sockfd);
    return 0;
}
