#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>             // For close()
#include <arpa/inet.h>          // For inet_addr, htons, etc.
#include <sys/socket.h>         // For socket(), sendto(), recvfrom()
#include <netinet/in.h>         // For sockaddr_in

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8877
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);
    char sendBuffer[BUFFER_SIZE];
    char recvBuffer[BUFFER_SIZE];

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    printf("Connected to UDP server at %s:%d\n", SERVER_IP, SERVER_PORT);
    printf("Type messages (type 'exit' to quit):\n");

    while (1) {
        printf("> ");
        fflush(stdout);
        fgets(sendBuffer, BUFFER_SIZE, stdin);

        // Remove trailing newline from fgets
        sendBuffer[strcspn(sendBuffer, "\n")] = '\0';

        // Exit if user types "exit"
        if (strcmp(sendBuffer, "exit") == 0) {
            break;
        }

        // Send message to server
        if (sendto(sockfd, sendBuffer, strlen(sendBuffer), 0,
                   (struct sockaddr*)&server_addr, addr_len) < 0) {
            perror("sendto failed");
            continue;
        }

        // Receive echo response
        int recv_len = recvfrom(sockfd, recvBuffer, BUFFER_SIZE - 1, 0,
                                (struct sockaddr*)&server_addr, &addr_len);
        if (recv_len < 0) {
            perror("recvfrom failed");
            continue;
        }

        recvBuffer[recv_len] = '\0';
        printf("Echo from server: \"%s\"\n", recvBuffer);
    }

    close(sockfd);
    return 0;
}
