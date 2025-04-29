#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 8080
#define BUFFER_SIZE 1024

int sock;
char username[50];

void *send_messages(void *arg) {
    char message[BUFFER_SIZE], formatted[BUFFER_SIZE + 50];
    while (fgets(message, BUFFER_SIZE, stdin)) {
        snprintf(formatted, sizeof(formatted), "%s: %s", username, message);
        send(sock, formatted, strlen(formatted), 0);
    }
    return NULL;
}

void *receive_messages(void *arg) {
    char buffer[BUFFER_SIZE];
    int bytes;
    while ((bytes = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes] = '\0';
        printf(">> %s", buffer);
    }
    printf("Server disconnected.\n");
    exit(0);
}

int main() {
    struct sockaddr_in server_addr;
    pthread_t send_thread, recv_thread;

    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  // Remove newline

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to server (Client 2).\n");

    pthread_create(&send_thread, NULL, send_messages, NULL);
    pthread_create(&recv_thread, NULL, receive_messages, NULL);

    pthread_join(send_thread, NULL);
    pthread_join(recv_thread, NULL);
    close(sock);
    return 0;
}
