// This is for Linux only

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>             // For close()
#include <arpa/inet.h>          // For inet_addr, htons, etc.
#include <sys/socket.h>         // For socket functions
#include <netinet/in.h>         // For sockaddr_in

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9999
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr, sender_addr;
    socklen_t addr_len = sizeof(server_addr);
    char sendBuffer[BUFFER_SIZE];
    char recvBuffer[BUFFER_SIZE];

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    printf("Enter message to send (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fflush(stdout);

        if (fgets(sendBuffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Input error\n");
            break;
        }

        // Remove trailing newline
        sendBuffer[strcspn(sendBuffer, "\n")] = '\0';

        // Exit condition
        if (strcmp(sendBuffer, "exit") == 0) {
            break;
        }

        // Send message to server
        if (sendto(sockfd, sendBuffer, strlen(sendBuffer), 0,
                   (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("sendto failed");
            continue;
        }

        // Receive response
        int recv_len = recvfrom(sockfd, recvBuffer, BUFFER_SIZE - 1, 0,
                                (struct sockaddr*)&sender_addr, &addr_len);
        if (recv_len < 0) {
            perror("recvfrom failed");
            continue;
        }

        recvBuffer[recv_len] = '\0'; // Null-terminate
        printf("Received from server: \"%s\"\n", recvBuffer);
    }

    close(sockfd);
    return 0;
}
