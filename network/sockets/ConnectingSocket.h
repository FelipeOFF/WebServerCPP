//
// Created by felip on 15/05/2021.
//

#ifndef WEBSERVERCPP_CONNECTINGSOCKET_H
#define WEBSERVERCPP_CONNECTINGSOCKET_H


#include "SimpleSocket.h"

namespace WSCPP {
    class ConnectingSocket : public SimpleSocket {
        ConnectingSocket(
            short domain,
            int service,
            int protocol,
            int port,
            u_long addrInterface);

        int connectToNetwork(SOCKET sock, sockaddr_in address) override;
    };
}


#endif //WEBSERVERCPP_CONNECTINGSOCKET_H
