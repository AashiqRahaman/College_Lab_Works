#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>             // For close()
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9999
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char sendBuffer[BUFFER_SIZE];
    char recvBuffer[BUFFER_SIZE];

    // Create TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to server. Type messages (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fflush(stdout);

        if (fgets(sendBuffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Input error\n");
            break;
        }

        sendBuffer[strcspn(sendBuffer, "\n")] = '\0'; // Remove newline

        if (strcmp(sendBuffer, "exit") == 0) {
            break;
        }

        // Send message
        if (send(sockfd, sendBuffer, strlen(sendBuffer), 0) < 0) {
            perror("Send failed");
            break;
        }

        // Receive echo
        int recv_len = recv(sockfd, recvBuffer, BUFFER_SIZE - 1, 0);
        if (recv_len < 0) {
            perror("Receive failed");
            break;
        }

        recvBuffer[recv_len] = '\0';
        printf("Received from server: \"%s\"\n", recvBuffer);
    }

    close(sockfd);
    return 0;
}
