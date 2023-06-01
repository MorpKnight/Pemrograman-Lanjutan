#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <omp.h>

#define SERVER "127.0.0.1"
#define PORT 8888

void connectServer(WSADATA *wsa, SOCKET *clientSocket, struct sockaddr_in *server){
    printf("Initialising Winsock...\n");
    if (WSAStartup(MAKEWORD(2, 2), wsa) != 0){
        printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Winsock Initialised.\n");

    if ((*clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
        printf("Could not create socket : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Socket created.\n");

    server->sin_addr.s_addr = inet_addr(SERVER);
    server->sin_family = AF_INET;
    server->sin_port = htons(PORT);

    if (connect(*clientSocket, (struct sockaddr *)server, sizeof(*server)) < 0){
        printf("Connect error");
        exit(EXIT_FAILURE);
    }
    printf("Connected!\n");
}

int main(){
    WSADATA wsa;
    SOCKET clientSocket;
    struct sockaddr_in server;
    char message[2000], serverReply[2000];
    int recvSize, totalThread;

    char *hello = "Hello from client";

    printf("Enter total thread: ");
    scanf("%d", &totalThread);

    #pragma omp parallel num_threads(totalThread) private(clientSocket)
    {
        connectServer(&wsa, &clientSocket, &server);
        
        // Send some data
        if((recvSize = recv(clientSocket, serverReply, 2000, 0)) > 0){
            serverReply[recvSize] = '\0';
            printf("Server reply: %s\n", serverReply);
        }

        send(clientSocket, hello, strlen(hello), 0);
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
