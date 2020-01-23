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
#include "SearchMatrix.h"
#include "MyClientHandler.h"
#include "SolverQA.h"
#include "MyParallelServer.h"

namespace boot {
    void firstCheck(int port) {
        Solver<string, string> *solver = new StringReverser();
        CacheManager<string, string> *cm = new FileCacheManager(5);
        server_side::Server *A = new MySerialServer();
        ClientHandler *B = new MyClientHandler(solver, cm);
        A->open(port, B);
        delete(A);
        delete(B);
    }
    class Main {
    public:
        void main(int port) {
            // Check program
           // firstCheck(port);

            // Real program
            Solver<string, string> *solver = new SolverQA();
            CacheManager<string, string> *cm = new FileCacheManager(5);
            server_side::Server *A = new MyParallelServer();
            ClientHandler *B = new MyClientHandler(solver, cm);
            A->open(port, B);
            delete(A);
            delete(B);

        }
    };

}

#endif //MILESTONE_2_MAIN_H
