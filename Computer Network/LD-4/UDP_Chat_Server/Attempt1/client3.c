#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

char username[50];
int sockfd;
struct sockaddr_in server_addr;

void *send_messages(void *arg) {
    char message[BUFFER_SIZE];
    char formatted[BUFFER_SIZE + 50];

    while (fgets(message, BUFFER_SIZE, stdin)) {
        snprintf(formatted, sizeof(formatted), "%s: %s", username, message);
        sendto(sockfd, formatted, strlen(formatted), 0,
               (struct sockaddr *)&server_addr, sizeof(server_addr));
    }
    return NULL;
}

void *receive_messages(void *arg) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in from_addr;
    socklen_t addr_len = sizeof(from_addr);
    while (1) {
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                         (struct sockaddr *)&from_addr, &addr_len);
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    return NULL;
}

int main() {
    printf("Enter your name as Client(3): ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = '\0';  // Remove newline

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    pthread_t send_thread, recv_thread;
    pthread_create(&send_thread, NULL, send_messages, NULL);
    pthread_create(&recv_thread, NULL, receive_messages, NULL);

    pthread_join(send_thread, NULL);
    pthread_join(recv_thread, NULL);

    close(sockfd);
    return 0;
}
