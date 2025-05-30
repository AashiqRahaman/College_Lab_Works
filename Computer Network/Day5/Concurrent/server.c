#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(client_sock, buffer, BUFFER_SIZE)) > 0) {
        buffer[n] = '\0';
        printf("Received: %s", buffer);
        write(client_sock, buffer, strlen(buffer));  // echo back
    }

    close(client_sock);
    exit(0);  // end child process
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pid_t child_pid;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) != 0) {
        perror("Bind failed");
        exit(1);
    }

    if (listen(server_sock, 5) != 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Concurrent TCP Server listening on port %d...\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);
        if (client_sock < 0) {
            perror("Server accept failed");
            continue;
        }

        // Forking to handle multiple clients
        child_pid = fork();
        if (child_pid == 0) {
            // Child process
            close(server_sock);  // Close child copy of server socket
            handle_client(client_sock);
        } else {
            // Parent process
            close(client_sock);  // Parent doesn't need this socket
        }
    }

    close(server_sock);
    return 0;
}
