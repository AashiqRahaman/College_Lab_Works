#include <winsock2.h>
#include <stdio.h>
#include <string.h>

int main() {
    const char* server_name = "localhost";
    const int server_port = 8877;

    WSADATA wsaData; // Winsock data structure
    SOCKET sock;     // Socket descriptor
    struct sockaddr_in server_address;
    int len;
    char buffer[100];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket\n");
        WSACleanup();
        return 1;
    }

    // Fill server_address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;

    // Convert server_name to binary form
    if (inet_pton(AF_INET, server_name, &server_address.sin_addr) <= 0) {
        printf("Invalid address\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // Set server port in network byte order
    server_address.sin_port = htons(server_port);

    // Data to send
    const char* data_to_send = "Gangadhar Hi Shaktimaan hai";

    // Send data
    len = sendto(sock, data_to_send, strlen(data_to_send), 0, 
                 (struct sockaddr*)&server_address, sizeof(server_address));

    if (len == SOCKET_ERROR) {
        printf("Send failed\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // Receive echoed data
    int recv_len = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, NULL, NULL);
    if (recv_len == SOCKET_ERROR) {
        printf("Receive failed\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    buffer[recv_len] = '\0'; // Null-terminate the received string
    printf("Received: '%s'\n", buffer);

    // Close the socket
    closesocket(sock);

    // Clean up Winsock
    WSACleanup();

    return 0;
}
