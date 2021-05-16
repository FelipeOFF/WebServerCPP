//
// Created by felip on 15/05/2021.
//

#ifndef WEBSERVERCPP_SIMPLESOCKET_H
#define WEBSERVERCPP_SIMPLESOCKET_H

#include <winsock.h>
#include <iostream>

namespace WSCPP {
    class SimpleSocket {
    private:
        struct sockaddr_in address{};
        SOCKET sock {INVALID_SOCKET};
        int connection {-1};
        int itemError {0};
    protected:
        SimpleSocket(short domain, int service, int protocol, int port, u_long addrInterface);
    public:
        virtual int connectToNetwork(SOCKET sock, struct sockaddr_in address) = 0;
        void testConnection(int);
        struct sockaddr_in getAddress();
        SOCKET getSock() const;
        int getConnection() const;
        void setConnection(int con);
        int haveError() const;
        ~SimpleSocket();
    };
}


#endif //WEBSERVERCPP_SIMPLESOCKET_H
