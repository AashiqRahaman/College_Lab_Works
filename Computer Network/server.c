#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <stdbool.h>  // Include for true/false constants

int main(int argc, char *argv[]) {
    // Port to start the server on
    int SERVER_PORT = 8877;

    // Winsock initialization
    WSADATA wsaData;
    SOCKET sock;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int client_address_len = sizeof(client_address);

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }

    // Create a UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == INVALID_SOCKET) {
        printf("Could not create socket\n");
        WSACleanup();
        return 1;
    }

    // Prepare the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind the socket to the address
    if (bind(sock, (struct sockaddr *)&server_address, sizeof(server_address)) == SOCKET_ERROR) {
        printf("Could not bind socket\n");
        closesocket(sock);
        WSACleanup();
        return 1;
    }

    // Run indefinitely
    while (true) {  // Now using 'true' after including stdbool.h
        char buffer[500];

        // Receive data from client
        int len = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *)&client_address, &client_address_len);
        if (len == SOCKET_ERROR) {
            printf("Error receiving data\n");
            continue;
        }

        // Null-terminate the received data
        buffer[len] = '\0';

        // Print the received message
        printf("Received: '%s' from client %s\n", buffer, inet_ntoa(client_address.sin_addr));

        // Send the same content back to the client (echo)
        if (sendto(sock, buffer, len, 0, (struct sockaddr *)&client_address, sizeof(client_address)) == SOCKET_ERROR) {
            printf("Error sending data\n");
        }
    }

    // Cleanup
    closesocket(sock);
    WSACleanup();
    return 0;
}
