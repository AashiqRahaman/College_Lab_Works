#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int client_fd;
    struct sockaddr_in server_addr;
    char buffer[128];
    socklen_t addr_len = sizeof(server_addr);

    client_fd = socket(AF_INET, SOCK_DGRAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5002);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send dummy request
    sendto(client_fd, "time", 4, 0,
           (struct sockaddr *)&server_addr, addr_len);

    // Receive server response
    recvfrom(client_fd, buffer, sizeof(buffer), 0,
             (struct sockaddr *)&server_addr, &addr_len);

    printf("Server time: %s", buffer);
    printf("Client Disconnected Successfully\n");
    close(client_fd);
    return 0;
}
