#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char buffer[128];
    time_t t;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5002);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);

    printf("TCP Day-Time Server running on port 5002...\n");

    while (1) {
        client_fd = accept(server_fd, NULL, NULL);
        t = time(NULL);
        snprintf(buffer, sizeof(buffer), "%s", ctime(&t));
        send(client_fd, buffer, strlen(buffer), 0);
        close(client_fd);
    }

    return 0;
}
