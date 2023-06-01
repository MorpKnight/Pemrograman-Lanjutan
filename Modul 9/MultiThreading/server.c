#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <omp.h> // Include OpenMP header

#define PORT 8888

void startServer(WSADATA *wsa, SOCKET *listenSocket, struct sockaddr_in *server){
    printf("Initialising Winsock...\n");
    if(WSAStartup(MAKEWORD(2, 2), wsa) != 0){
        printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Winsock Initialised.\n");

    if((*listenSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
        printf("Could not create socket : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Socket created.\n");

    server->sin_family = AF_INET;
    server->sin_addr.s_addr = INADDR_ANY;
    server->sin_port = htons(PORT);

    if(bind(*listenSocket, (struct sockaddr *)server, sizeof(*server)) == SOCKET_ERROR){
        printf("Bind failed with error code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Bind done!\n");

    listen(*listenSocket, 3);

    printf("Waiting for incoming connections...\n");
}

int main(){
    WSADATA wsa;
    SOCKET listenSocket, clientSocket;
    struct sockaddr_in server;
    int recvSize, i;

    char clientMessage[2000];
    char *message = "Hello Client, I have received your connection. But I have to go now, bye\n";
    i = 0;

    startServer(&wsa, &listenSocket, &server);

    // Initialize OpenMP parallel region with dynamic scheduling
    #pragma omp parallel num_threads(16) shared(listenSocket) private(clientSocket)
    {
        int threadNum = omp_get_thread_num();
        int connectedThreads[16] = {0};
        int connectedCount = 0;

        while (1) {
            // Accept a new client connection
            #pragma omp critical
            {
                clientSocket = accept(listenSocket, NULL, NULL);
                if (clientSocket == INVALID_SOCKET) {
                    printf("Accept failed with error code : %d", WSAGetLastError());
                    exit(EXIT_FAILURE);
                }
                connectedThreads[connectedCount++] = threadNum;
                if (connectedCount == omp_get_num_threads()) {
                    printf("Connection accepted by thread ");
                    for (int j = 0; j < connectedCount; j++) {
                        printf("%d", connectedThreads[j]);
                        if (j != connectedCount - 1)
                            printf(", ");
                    }
                    printf("\n");
                }
                else {
                    closesocket(clientSocket);
                    continue;
                }
            }

            // Process client request here
            send(clientSocket, message, strlen(message), 0);

            // Receive a reply from the client
            if((recvSize = recv(clientSocket, clientMessage, 2000, 0)) > 0){
                clientMessage[recvSize] = '\0';
                printf("Client reply : %s\n", clientMessage);
                printf("Request %d\n", ++i);
            }

            // Close the client socket
            closesocket(clientSocket);
        }
    }

    closesocket(listenSocket);
    WSACleanup();

    return 0;
}
