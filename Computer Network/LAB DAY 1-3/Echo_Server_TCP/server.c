#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>             // For close()
#include <arpa/inet.h>          // For socket(), bind(), listen(), accept(), recv(), send()
#include <netinet/in.h>

#define SERVER_PORT 9999
#define BUFFER_SIZE 500

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, 5) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("TCP server listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Accept a client connection
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected: %s:%d\n",
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));

        // Communicate with client
        int len;
        while ((len = recv(client_fd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
            buffer[len] = '\0';
            printf("Received: '%s'\n", buffer);

            // Echo back
            if (send(client_fd, buffer, len, 0) < 0) {
                perror("Send failed");
                break;
            }
        }

        printf("Client disconnected\n");
        close(client_fd);
    }

    close(server_fd);
    return 0;
}
