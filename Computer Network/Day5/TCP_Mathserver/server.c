#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h>
#define PORT 13013 // You can change the port if needed 
#define MAX_BUFFER_SIZE 256
double perform_operation(char *operation, double num1, double num2) { if (strcmp(operation, "add") == 0) {
return num1 + num2;
} else if (strcmp(operation, "subtract") == 0) { return num1 - num2;
} else if (strcmp(operation, "multiply") == 0) { return num1 * num2;
} else if (strcmp(operation, "divide") == 0) { if (num2 == 0) { return -1;  } // Return -1 for division by zero error  
return num1 / num2;
} else {
return -2; }}   // Invalid operation
int main() {
int server_fd, client_fd;
struct sockaddr_in server_addr, client_addr; socklen_t client_len = sizeof(client_addr); char buffer[MAX_BUFFER_SIZE];
int bytes_received;
double num1, num2, result; char operation[10];
server_fd = socket(AF_INET, SOCK_STREAM, 0); if (server_fd < 0) {
perror("Socket creation failed"); exit(EXIT_FAILURE);}
memset(&server_addr, 0, sizeof(server_addr)); server_addr.sin_family = AF_INET; server_addr.sin_addr.s_addr = INADDR_ANY;
server_addr.sin_port = htons(PORT);
if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) { perror("Bind failed");
close(server_fd); exit(EXIT_FAILURE);
}
if (listen(server_fd, 1) < 0) { perror("Listen failed"); close(server_fd); exit(EXIT_FAILURE);}
printf("Server listening on port %d...\n", PORT);
client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_len); if (client_fd < 0) {
perror("Accept failed"); close(server_fd); exit(EXIT_FAILURE);}
printf("Client connected.\n"); while (1) {
memset(buffer, 0, MAX_BUFFER_SIZE);
bytes_received = recv(client_fd, buffer, MAX_BUFFER_SIZE - 1, 0); if (bytes_received <= 0) {
printf("Client disconnected or error occurred\n"); break;}
sscanf(buffer, "%s %lf %lf", operation, &num1, &num2); result = perform_operation(operation, num1, num2);
if (result == -1) {
snprintf(buffer, sizeof(buffer), "Error: Division by zero");
} else if (result == -2) {
snprintf(buffer, sizeof(buffer), "Error: Invalid operation");
} else {
snprintf(buffer, sizeof(buffer), "Result: %.2f", result);}
send(client_fd, buffer, strlen(buffer), 0);}
close(client_fd); close(server_fd); printf("Server finished.\n"); 
return 0;}
