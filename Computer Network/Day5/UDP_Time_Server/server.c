#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[128];
    time_t t;

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5002);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("UDP Day-Time Server running on port 5002...\n");

    while (1) {
        // Wait for client request
        recvfrom(server_fd, buffer, sizeof(buffer), 0,
                 (struct sockaddr *)&client_addr, &addr_len);

        t = time(NULL);
        snprintf(buffer, sizeof(buffer), "%s", ctime(&t));

        // Send time to client
        sendto(server_fd, buffer, strlen(buffer), 0,
               (struct sockaddr *)&client_addr, addr_len);
    }

    return 0;
}
