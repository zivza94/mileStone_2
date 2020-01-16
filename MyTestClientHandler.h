//
// Created by liza on 16/01/2020.
//

#ifndef MILESTONE_2_MYTESTCLIENTHANDLER_H
#define MILESTONE_2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
public:
    void handleClient(int clientSocket);
};


#endif //MILESTONE_2_MYTESTCLIENTHANDLER_H
