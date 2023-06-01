#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ctype.h>

#define PORT 8888

void encrypt(char message[100]){
    int i;

    for(i = 0; i < strlen(message); i++){
        if(message[i] == 32){
            continue;
        } else if(message[i] >= 120 && message[i] <= 122){
            message[i] -= 23;
        } else {
            message[i] += 3;
        }
    }
}

void decrypt(char message[2000]){
    int i;

    for(i = 0; i < strlen(message); i++){
        if(message[i] == 32){
            continue;
        } else if(message[i] <= 99 && message[i] >= 97){
            message[i] += 23;
        }else {
            message[i] -= 3;
        }
    }
}

void lowerMessagee(char message[100]){
    int i;
    for(i = 0; i < strlen(message); i++){
        message[i] = tolower(message[i]);
    }
}

int checkNum(char message[100]){
    int i, check;

    check = 0;
    for(i = 0; i < strlen(message); i++){
        if(message[i] >= 48 && message[i] <= 57){
            check = 1;
        }
    }

    return check;
}

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

int main(){
    WSADATA wsa;
    SOCKET listenSocket, clientSocket;

    struct sockaddr_in server, client;
    int c, recvSize, i, check;

    char clientMessage[2000], message[100];

    check = 0;
    startServer(&wsa, &listenSocket, &clientSocket, &server, &client, &c);

    // minta input pesan rahasia
    do {
        printf("Enter message to send to client: ");
        gets(message);
        check = checkNum(message);

        // handler jika ada angka
    } while(check != 0);

    lowerMessagee(message);

    // enkripsi
    encrypt(message);

    // menampilkan enkripsi
    printf("Encrypted message: ");
    for(i = 0; i < strlen(message); i++){
        printf("%c", message[i]);
    }
    printf("\n");

    // kirim enkripsi
    send(clientSocket, message, strlen(message), 0);

    // menerima feedback
    if ((recvSize = recv(clientSocket, clientMessage, 2000, 0)) == SOCKET_ERROR) {
        printf("recv failed with error code : %d", WSAGetLastError());
    } else {
        clientMessage[recvSize] = '\0';
    }

    // print feedback
    printf("Received message from client: ");
    for(i = 0; i < strlen(clientMessage); i++){
        printf("%c", clientMessage[i]);
    }

    // dekripsi pesan
    decrypt(clientMessage);

    // print hasil dekripsi
    printf("\nDecrypted message: ");
    for(i = 0; i < strlen(clientMessage); i++){
        printf("%c", clientMessage[i]);
    }

    closesocket(listenSocket);
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}