#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 1111
#define BUFFER_SIZE 1024

int sock;
char username[50];

void xor_decrypt(char *message) {
    for (int i = 0; message[i]; i++) {
        message[i] ^= 100;
    }
}

void *receive_messages(void *arg) {
    char buffer[BUFFER_SIZE];
    int bytes;
    while ((bytes = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes] = '\0';
        xor_decrypt(buffer);  // Decrypt received message
        printf(">> %s", buffer);
    }
    printf("Disconnected from server.\n");
    exit(0);
}

void *send_messages(void *arg) {
    char message[BUFFER_SIZE];
    char formatted[BUFFER_SIZE + 50];
    while (fgets(message, BUFFER_SIZE, stdin)) {
        snprintf(formatted, sizeof(formatted), "%s: %s", username, message);
        send(sock, formatted, strlen(formatted), 0);
    }
    return NULL;
}

int main() {
    struct sockaddr_in server_addr;
    pthread_t send_thread, recv_thread;

    printf("Enter your name as Client(1): ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to server as '%s'. Type your messages:\n", username);

    pthread_create(&send_thread, NULL, send_messages, NULL);
    pthread_create(&recv_thread, NULL, receive_messages, NULL);

    pthread_join(send_thread, NULL);
    pthread_join(recv_thread, NULL);

    close(sock);
    return 0;
}
