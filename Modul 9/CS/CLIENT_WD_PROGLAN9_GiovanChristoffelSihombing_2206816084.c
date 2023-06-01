#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <string.h>
#include <ctype.h>

#define SERVER "127.0.0.1"
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
        } else {
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

void connectServer(WSADATA *wsa, SOCKET *clientSocket, struct sockaddr_in *server){
    printf("Initialising Winsock...\n");
    if(WSAStartup(MAKEWORD(2, 2), wsa) != 0){
        printf("WSAStartup failed. Error Code : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Winsock Initialised.\n");

    if((*clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET){
        printf("Could not create socket : %d", WSAGetLastError());
        exit(EXIT_FAILURE);
    }
    printf("Socket created.\n");

    server->sin_addr.s_addr = inet_addr(SERVER);
    server->sin_family = AF_INET;
    server->sin_port = htons(PORT);

    if(connect(*clientSocket, (struct sockaddr *)server, sizeof(*server)) < 0){
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
    int recvSize, i, check;

    connectServer(&wsa, &clientSocket, &server);

    if((recvSize = recv(clientSocket, serverReply, 2000, 0)) == SOCKET_ERROR){
        printf("Recv failed with error code : %d", WSAGetLastError());
    } else {
        serverReply[recvSize] = '\0';
    }

    printf("Received message from server: ");
    for(i = 0; i < strlen(serverReply); i++){
        printf("%c", serverReply[i]);
    }

    // dekripsi pesan dari server
    printf("\nDecrypted message from server: ");
    decrypt(serverReply);

    for(i = 0; i < strlen(serverReply); i++){
        printf("%c", serverReply[i]);
    }

    // meminta input pesan yang akan dikirim ke server
    do {
        printf("\nEnter message to send to client: ");
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

    return 0;
}