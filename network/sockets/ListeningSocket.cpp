//
// Created by felip on 15/05/2021.
//

#include "ListeningSocket.h"

WSCPP::ListeningSocket::ListeningSocket(short domain, int service, int protocol, int port, u_long addrInterface, int bklg) : BindingSocket(domain, service, protocol, port, addrInterface) {
    backlog = bklg;
    startListening();
    testConnection(listening);
}

void WSCPP::ListeningSocket::startListening() {
    listening = listen(getSock(), backlog);
}
