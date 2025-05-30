#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h>
#define PORT 13013 // Same port as the server 
#define MAX_BUFFER_SIZE 256
int main() {
int sock_fd;
struct sockaddr_in server_addr; char buffer[MAX_BUFFER_SIZE]; char operation[10];
double num1, num2;
sock_fd = socket(AF_INET, SOCK_STREAM, 0); if (sock_fd < 0) {
perror("Socket creation failed"); exit(EXIT_FAILURE);}
memset(&server_addr, 0, sizeof(server_addr));
server_addr.sin_family = AF_INET; server_addr.sin_port = htons(PORT);
if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) { perror("Invalid address");
close(sock_fd); exit(EXIT_FAILURE);}
if (connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) { perror("Connection failed");
close(sock_fd); exit(EXIT_FAILURE);}
printf("Connected to server.\n"); while (1) {
printf("Enter operation (add, subtract, multiply, divide) followed by two numbers: ");
if (scanf("%s %lf %lf", operation, &num1, &num2) != 3) { printf("Invalid input format\n");
continue;}
snprintf(buffer, sizeof(buffer), "%s %lf %lf", operation, num1, num2); send(sock_fd, buffer, strlen(buffer), 0);
memset(buffer, 0, MAX_BUFFER_SIZE);
recv(sock_fd, buffer, MAX_BUFFER_SIZE - 1, 0); printf("Server response: %s\n", buffer);
char choice;
printf("Do you want to perform another operation? (y/n): "); scanf(" %c", &choice);
if (choice != 'y' && choice != 'Y') { break;}   }
close(sock_fd); printf("Client finished.\n"); 
return 0;}