#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER "127.0.0.1"
#define PORT 8888

int main(int argc, char *argv[]) {
    WSADATA wsa;
    SOCKET client_socket;
    struct sockaddr_in server;
    char message[2000], server_reply[2000];
    int recv_size;

    printf("Initialising Winsock...\n");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("WSAStartup failed. Error code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Winsock initialised.\n");

    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket. Error code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Socket created.\n");

    server.sin_addr.s_addr = inet_addr(SERVER);
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);

    if (connect(client_socket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Connection failed. Error code: %d\n", WSAGetLastError());
        return 1;
    }
    printf("Connected to server.\n");

    // Receive a message from the server
    if ((recv_size = recv(client_socket, server_reply, 2000, 0)) > 0) {
        server_reply[recv_size] = '\0';
        printf("Received message from server: %s\n", server_reply);
    }
    
    // Send a "Hello from server" message to the server
    char *hello = "Hello from client";
    send(client_socket, hello, strlen(hello), 0);

    closesocket(client_socket);
    WSACleanup();
    
    return 0;
}