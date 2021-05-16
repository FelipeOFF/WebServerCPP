//
// Created by felip on 15/05/2021.
//

#ifndef WEBSERVERCPP_TESTSERVER_H
#define WEBSERVERCPP_TESTSERVER_H

#include "SimpleServer.h"
#include <io.h>

namespace WSCPP {
    class TestServer : public SimpleServer{
    private:
        char buffer[30000] = {0};
        SOCKET newSocket{INVALID_SOCKET};

        int accepter() override;
        void handler() override;
        int responder() override;
        static bool checkBlock(int result);
        int shutdownConnectionSend() override;
    public:
        TestServer();
        ~TestServer();
        void launch() override;
    };
}


#endif //WEBSERVERCPP_TESTSERVER_H
