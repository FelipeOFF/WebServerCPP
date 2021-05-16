//
// Created by felip on 15/05/2021.
//

#include "SimpleSocket.h"

WSCPP::SimpleSocket::SimpleSocket(short domain, int service, int protocol, int port, u_long addrInterface) {
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(addrInterface);

    WSADATA wsaData = {0};

    // Initialize Winsock
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        wprintf(L"WSAStartup failed: %d\n", result);
        std::cerr << "WSAStartup failed: " << result << std::endl;
        WSACleanup();
    }

    sock = socket(domain, service, protocol);
    if (sock == INVALID_SOCKET || sock == SOCKET_ERROR) {
        std::cerr << "Socket Error: " << WSAGetLastError() << std::endl;
    }
    testConnection((int) sock);
}

void WSCPP::SimpleSocket::testConnection(int itemToTest) {
    if(itemToTest < 0) {
        std::cerr << "Failed to connect" << std::endl;
        std::cerr << "listen function failed with error: " << WSAGetLastError() << std::endl;
        itemError = itemToTest;
    }
}

struct sockaddr_in WSCPP::SimpleSocket::getAddress() {
    return address;
}

SOCKET WSCPP::SimpleSocket::getSock() const {
    return sock;
}

int WSCPP::SimpleSocket::getConnection() const {
    return connection;
}

void WSCPP::SimpleSocket::setConnection(int con) {
    connection = con;
}

WSCPP::SimpleSocket::~SimpleSocket() {
    if (sock != INVALID_SOCKET) {
        std::cout << "Socket exist need close" << std::endl;
        int result = closesocket(sock);
        if (result == SOCKET_ERROR) {
            std::cerr << "socket close failed: " << result << std::endl;
        }
    }
    WSACleanup();
}

int WSCPP::SimpleSocket::haveError() const {
    return itemError;
}


