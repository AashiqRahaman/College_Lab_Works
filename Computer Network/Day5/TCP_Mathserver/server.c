#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    int num1, num2, result;
    char op;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6000);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);

    printf("Math TCP Server running on port 6000...\n");

    while (1) {
        client_fd = accept(server_fd, NULL, NULL);

        read(client_fd, &num1, sizeof(num1));
        read(client_fd, &num2, sizeof(num2));
        read(client_fd, &op, sizeof(op));

        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': result = num2 != 0 ? num1 / num2 : 0; break;
            default: result = 0; break;
        }

        write(client_fd, &result, sizeof(result));
        close(client_fd);
    }

    return 0;
}
