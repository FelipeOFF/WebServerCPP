cmake_minimum_required(VERSION 3.19)
project(WebServerCPP)

set(CMAKE_CXX_STANDARD 11)

add_executable(WebServerCPP main.cpp network/sockets/SimpleSocket.cpp network/sockets/SimpleSocket.h network/sockets/BindingSocket.cpp network/sockets/BindingSocket.h network/sockets/ConnectingSocket.cpp network/sockets/ConnectingSocket.h network/sockets/ListeningSocket.cpp network/sockets/ListeningSocket.h network/sockets/WSCPPlibcSockets.h network/WSCPPlibcNetworking.h network/server/SimpleServer.cpp network/server/SimpleServer.h network/server/TestServer.cpp network/server/TestServer.h network/server/WSCPPlibcServer.h)

if(WIN32)
    target_link_libraries(WebServerCPP wsock32.lib ws2_32.lib)
endif()