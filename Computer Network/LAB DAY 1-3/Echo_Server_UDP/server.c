#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>             // For close()
#include <arpa/inet.h>          // For inet_ntoa, htons, etc.
#include <sys/socket.h>         // For socket(), bind(), recvfrom(), sendto()
#include <netinet/in.h>         // For sockaddr_in
#include <stdbool.h>            // For bool, true, false

#define SERVER_PORT 9999
#define BUFFER_SIZE 500

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Zero out the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("UDP server listening on port %d...\n", SERVER_PORT);

    // Server loop
    while (true) {
        int len = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                           (struct sockaddr*)&client_addr, &client_addr_len);
        if (len < 0) {
            perror("Error receiving data");
            continue;
        }

        buffer[len] = '\0';  // Null-terminate received data

        printf("Received: '%s' from client %s:%d\n",
               buffer,
               inet_ntoa(client_addr.sin_addr),
               ntohs(client_addr.sin_port));

        // Echo the message back to the client
        if (sendto(sockfd, buffer, len, 0,
                   (struct sockaddr*)&client_addr, client_addr_len) < 0) {
            perror("Error sending data");
        }
    }

    // Cleanup (not reachable unless loop exits)
    close(sockfd);
    return 0;
}
