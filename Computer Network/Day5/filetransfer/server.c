#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9991
#define BUFFER_SIZE 1024

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    FILE *fp;
    socklen_t addr_size;
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);
    printf("File Server waiting on port %d...\n", PORT);

    int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &addr_size);
    
    // Send file
    fp = fopen("test.txt", "rb");
    if (!fp) {
        perror("File open error");
        exit(1);
    }

    while (!feof(fp)) {
        int n = fread(buffer, 1, BUFFER_SIZE, fp);
        send(client_fd, buffer, n, 0);
    }

    fclose(fp);
    close(client_fd);
    close(server_fd);
    printf("File sent successfully.\n");
    return 0;
}
