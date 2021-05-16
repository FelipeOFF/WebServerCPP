#include <iostream>

#include "network/server/WSCPPlibcServer.h"

int main() {

    auto *ts = new WSCPP::TestServer();
    ts->launch();

    if (!ts->getSocket()->haveError()) {
        std::cout << "Success..." << " TS: " << ts->getSocket()->haveError() << std::endl;
    } else {
        std::cerr << "Error: " << " TS: " << ts->getSocket()->haveError() << std::endl;
    }

    delete ts;

    return 0;
}
