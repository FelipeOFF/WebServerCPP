//
// Created by felip on 15/05/2021.
//

#ifndef WEBSERVERCPP_SIMPLESERVER_H
#define WEBSERVERCPP_SIMPLESERVER_H

#include "../sockets/WSCPPlibcSockets.h"

namespace WSCPP {
    class SimpleServer {
    private:
        ListeningSocket *socket;
        virtual int accepter() = 0;
        virtual void handler() = 0;
        virtual int responder() = 0;
        virtual int shutdownConnectionSend() = 0;
    public:
        SimpleServer(short domain, int service, int protocol, int port, u_long addrInterface, int bklg);
        virtual void launch() = 0;
        ListeningSocket * getSocket();
        ~SimpleServer();
    };
}


#endif //WEBSERVERCPP_SIMPLESERVER_H
