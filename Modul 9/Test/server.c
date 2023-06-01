#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define PORT 8888

void startServer(WSADATA *wsa, SOCKET *listenSocket, SOCKET *clientSocket, struct sockaddr_in *server, struct sockaddr_in *client, int *c) {
    printf("Initialising Winsock...\n");
    if (WSAStartup(MAKEWORD(2, 2), wsa) != 0) {
        printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Winsock Initialised.\n");

    if ((*listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Could not create socket : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Socket created.\n");

    server->sin_family = AF_INET;
    server->sin_addr.s_addr = INADDR_ANY;
    server->sin_port = htons(PORT);

    if (bind(*listenSocket, (struct sockaddr*)server, sizeof(*server)) == SOCKET_ERROR) {
        printf("Bind failed with error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Bind done!\n");

    listen(*listenSocket, 3);

    printf("Waiting for incoming connections...\n");
    *c = sizeof(struct sockaddr_in);

    if ((*clientSocket = accept(*listenSocket, (struct sockaddr*)client, c)) == INVALID_SOCKET) {
        printf("Accept failed with error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Connection accepted!\n");
}

int main() {
    WSADATA wsa;
    SOCKET listenSocket, clientSocket;

    struct sockaddr_in server, client;
    int c, recvSize;

    char clientMessage[2000], message[100];

    startServer(&wsa, &listenSocket, &clientSocket, &server, &client, &c);

    printf("Enter message: ");
    gets(message);

    send(clientSocket, message, strlen(message), 0);

    if ((recvSize = recv(clientSocket, clientMessage, 2000, 0)) == SOCKET_ERROR) {
        printf("recv failed with error code : %d", WSAGetLastError());
    }
    else {
        clientMessage[recvSize] = '\0';
        printf("Client reply: %s\n", clientMessage);
    }

    closesocket(listenSocket);
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
