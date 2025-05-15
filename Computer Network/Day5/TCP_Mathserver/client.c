#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 6000
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server;
    char expression[BUFFER_SIZE], response[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    connect(sock, (struct sockaddr*)&server, sizeof(server));

    printf("Enter math expression (e.g., 5*3+10/2): ");
    fgets(expression, BUFFER_SIZE, stdin);

    send(sock, expression, strlen(expression), 0);
    recv(sock, response, sizeof(response) - 1, 0);

    printf("%s\n", response);

    close(sock);
    return 0;
}
