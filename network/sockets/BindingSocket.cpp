//
// Created by felip on 15/05/2021.
//

#include "BindingSocket.h"


WSCPP::BindingSocket::BindingSocket(short domain, int service, int protocol, int port, u_long addrInterface) : SimpleSocket(
    domain,
    service,
    protocol,
    port,
    addrInterface) {
    setConnection(connectToNetwork(getSock(), getAddress()));
    testConnection(getConnection());
}

int WSCPP::BindingSocket::connectToNetwork(SOCKET sock, struct sockaddr_in address) {
    return bind(sock, (struct sockaddr*)&address, sizeof(address));
}