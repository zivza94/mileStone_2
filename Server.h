//
// Created by ziv on 13/01/2020.
//

#ifndef MILESTONE_2_SERVER_H
#define MILESTONE_2_SERVER_H

#include "ClientHandler.h"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <thread>

namespace server_side {
    class Server{
    public:
        virtual void open (int port,ClientHandler *clientHandler) = 0;
        virtual void stop () = 0;
        virtual ~Server(){} ;
    };
}
#endif //MILESTONE_2_SERVER_H
