//
// Created by felip on 15/05/2021.
//

#include "TestServer.h"

WSCPP::TestServer::TestServer()
    : SimpleServer(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, SOMAXCONN) {
}

int WSCPP::TestServer::accepter() {
    struct sockaddr_in address = getSocket()->getAddress();
    int addressSize = sizeof(address);
    newSocket = accept(getSocket()->getSock(), (struct sockaddr *)&address, &addressSize);
    if (newSocket != SOCKET_ERROR) {
        return recv(newSocket, buffer, 30000, 0);
    } else {
        return (int) newSocket;
    }
}

void WSCPP::TestServer::handler() {
    std::cout << buffer << std::endl;
}

int WSCPP::TestServer::responder() {
    std::string hello = "HTTP/1.1 200 OK\n"
                        "Access-Control-Allow-Credentials: true\n"
                        "Content-Type: application/json; charset=utf-8\n\n"
                        "{\"message\": \"Hello World\"}";
    if (newSocket != SOCKET_ERROR) {
        return send(newSocket, hello.c_str(), (int)strlen(hello.c_str()), 0);
    } else {
        return (int) newSocket;
    }
}

int WSCPP::TestServer::shutdownConnectionSend() {
    return shutdown(newSocket, 1);
}

void WSCPP::TestServer::launch() {
    int result;
    int stop;
    do {
        std::cout << "========= WAITING =========" << std::endl;
        result = accepter();

        if (checkBlock(result)) {
            break;
        }

        handler();
        result = responder();
        if (checkBlock(result)) {
            break;
        }

        shutdownConnectionSend();

        std::cout << "========= DONE =========" << std::endl;

        std::cout << "You wanna stop? Digit 1" << std::endl;
        std::cin >> stop;
    } while(result > 0 && stop > 0);
}

bool WSCPP::TestServer::checkBlock(int result) {
    if (result == SOCKET_ERROR) {
        std::cerr << "Socket Error: " << WSAGetLastError() << std::endl;
        return true;
    } else if (result > 0) {
        std::cout << "Result received: " << result << std::endl;
    } else if (result == 0) {
        std::cout << "Server close" << std::endl;
    } else {
        std::cerr << "recv failed: " << WSAGetLastError() << std::endl;
    }
    return false;
}

WSCPP::TestServer::~TestServer() {
    if (newSocket != INVALID_SOCKET) {
        std::cout << "Socket exist need close" << std::endl;
        int result = closesocket(newSocket);
        if (result == SOCKET_ERROR) {
            std::cerr << "socket close failed: " << result << std::endl;
        }
    }
    WSACleanup();
}
