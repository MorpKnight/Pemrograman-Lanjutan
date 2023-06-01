#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <omp.h>

int initializeWinsock(WSADATA *wsaData) {
    if (WSAStartup(MAKEWORD(2, 2), wsaData) != 0) {
        printf("Failed to initialize Winsock\n");
        return 0;
    }
    return 1;
}

void cleanupWinsock() {
    WSACleanup();
}

SOCKET createTCPSocket() {
    SOCKET tcpSocket;
    if ((tcpSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        printf("Failed to create TCP socket\n");
        return INVALID_SOCKET;
    }
    return tcpSocket;
}

void scanPort(const char* ipAddress, int port) {
    WSADATA wsaData;
    SOCKET tcpSocket;
    struct sockaddr_in server;
    int connectionResult;

    if (!initializeWinsock(&wsaData)) {
        return;
    }

    tcpSocket = createTCPSocket();
    if (tcpSocket == INVALID_SOCKET) {
        cleanupWinsock();
        return;
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ipAddress);
    server.sin_port = htons(port);

    connectionResult = connect(tcpSocket, (struct sockaddr*)&server, sizeof(server));
    if (connectionResult == SOCKET_ERROR) {
        printf("Port %d: Closed\n", port);
    } else {
        printf("Port %d: Open\n", port);
    }

    closesocket(tcpSocket);

    cleanupWinsock();
}

int main() {
    const char* ipAddress = "127.0.0.1";
    int startPort = 8000;
    int endPort = 9000;

    printf("Port Scanner\n");
    printf("Scanning IP address: %s\n", ipAddress);
    printf("Scanning ports from %d to %d\n", startPort, endPort);

    #pragma omp parallel for
    for (int port = startPort; port <= endPort; ++port) {
        scanPort(ipAddress, port);
    }

    return 0;
}
