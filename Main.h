//
// Created by liza on 18/01/2020.
//

#ifndef MILESTONE_2_MAIN_H
#define MILESTONE_2_MAIN_H


#include "Server.h"
#include "StringReverser.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "FileCacheManager.h"

namespace boot {

    class Main {
    public:
        void main(int port) {
            Solver<string, string> *solver = new StringReverser();
            CacheManager<string, string> *cm = new FileCacheManager(5);
            server_side::Server *A = new MySerialServer();
            ClientHandler *B = new MyTestClientHandler(solver, cm);
            A->open(port, B);
      //     delete(A);
            delete(B);

        }
    };

}

#endif //MILESTONE_2_MAIN_H
