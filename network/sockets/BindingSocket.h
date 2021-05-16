//
// Created by felip on 15/05/2021.
//

#ifndef WEBSERVERCPP_BINDINGSOCKET_H
#define WEBSERVERCPP_BINDINGSOCKET_H

#include <winsock.h>

#include "SimpleSocket.h"

namespace WSCPP {
    class BindingSocket : public SimpleSocket {
    public:
        BindingSocket(
            short domain,
            int service,
            int protocol,
            int port,
            u_long addrInterface);

        int connectToNetwork(SOCKET sock, sockaddr_in address) override;
    };
}


#endif //WEBSERVERCPP_BINDINGSOCKET_H
