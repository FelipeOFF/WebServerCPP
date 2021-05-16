//
// Created by felip on 15/05/2021.
//

#include "ConnectingSocket.h"

WSCPP::ConnectingSocket::ConnectingSocket(short domain, int service, int protocol, int port, u_long addrInterface) : SimpleSocket(
    domain,
    service,
    protocol,
    port,
    addrInterface) {
    setConnection(connectToNetwork(getSock(), getAddress()));
    testConnection(getConnection());
}

int WSCPP::ConnectingSocket::connectToNetwork(SOCKET sock, struct sockaddr_in address) {
    return connect(sock, (struct sockaddr*)&address, sizeof(address));
}