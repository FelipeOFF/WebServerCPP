//
// Created by felip on 15/05/2021.
//

#include "SimpleServer.h"

WSCPP::SimpleServer::SimpleServer(short domain, int service, int protocol, int port, u_long addrInterface, int bklg) {
    socket = new ListeningSocket(domain, service, protocol, port, addrInterface, bklg);
}

WSCPP::ListeningSocket *WSCPP::SimpleServer::getSocket() {
    return socket;
}

WSCPP::SimpleServer::~SimpleServer() {
    delete socket;
}
