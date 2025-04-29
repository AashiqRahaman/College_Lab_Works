#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void *handle_client(void *client_socket_ptr) {
    int client_socket = *(int *)client_socket_ptr;
    free(client_socket_ptr);  // Free dynamically allocated memory
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            close(client_socket);
            pthread_exit(NULL);
        }

        printf("Client: %s", buffer);

        printf("Server: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(client_socket, buffer, strlen(buffer), 0);
    }

    return NULL;
}

int main() {
    int server_fd, *client_socket_ptr;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);

    pthread_t thread_id;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        client_socket_ptr = malloc(sizeof(int));
        if (!client_socket_ptr) {
            perror("Malloc failed");
            continue;
        }

        *client_socket_ptr = accept(server_fd, (struct sockaddr *)&address, &addrlen);
        if (*client_socket_ptr < 0) {
            perror("Accept failed");
            free(client_socket_ptr);
            continue;
        }

        printf("New client connected.\n");

        // Create a new thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, client_socket_ptr) != 0) {
            perror("Thread creation failed");
            close(*client_socket_ptr);
            free(client_socket_ptr);
        }

        // Optionally detach thread if you don't plan to join it
        pthread_detach(thread_id);
    }

    close(server_fd);
    return 0;
}
