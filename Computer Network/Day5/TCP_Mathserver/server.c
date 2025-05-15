#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "tinyexpr.h"

#define PORT 6000
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr;
    char expr[BUFFER_SIZE];
    char result_str[BUFFER_SIZE];
    double result;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 5);

    printf("Math Expression Server running on port %d...\n", PORT);

    while (1) {
        client_fd = accept(server_fd, NULL, NULL);
        memset(expr, 0, sizeof(expr));
        read(client_fd, expr, sizeof(expr));

        printf("Received expression: %s\n", expr);

        result = te_interp(expr, 0); // Interpret expression

        if (isnan(result)) {
            snprintf(result_str, sizeof(result_str), "Error: Invalid expression or division by zero.");
        } else {
            snprintf(result_str, sizeof(result_str), "Result: %.2f", result);
        }

        write(client_fd, result_str, strlen(result_str));
        close(client_fd);
    }

    return 0;
}
