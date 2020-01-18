//
// Created by liza on 16/01/2020.
//

#ifndef MILESTONE_2_CLIENTHANDLER_H
#define MILESTONE_2_CLIENTHANDLER_H

#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>

using namespace std;
class ClientHandler {
public:
    virtual void handleClient(int clientSocket) = 0;
    virtual ~ClientHandler(){} ;
};

#endif //MILESTONE_2_CLIENTHANDLER_H
