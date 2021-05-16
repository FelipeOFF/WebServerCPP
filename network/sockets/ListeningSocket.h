//
// Created by felip on 15/05/2021.
//

#ifndef WEBSERVERCPP_LISTENINGSOCKET_H
#define WEBSERVERCPP_LISTENINGSOCKET_H

#include "BindingSocket.h"

namespace WSCPP {
    class ListeningSocket : public BindingSocket{
    private:
        int backlog;
        int listening{-1};
    public:
        ListeningSocket(short domain, int service, int protocol, int port, u_long addrInterface, int bklg);
        void startListening();
    };
}


#endif //WEBSERVERCPP_LISTENINGSOCKET_H
