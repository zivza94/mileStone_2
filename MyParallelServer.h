//
// Created by liza on 22/01/2020.
//

#ifndef MILESTONE_2_MYPARALLELSERVER_H
#define MILESTONE_2_MYPARALLELSERVER_H


#include "ClientHandler.h"
#include "Server.h"
#include <thread>

struct acceptInfo1 {
    int port;
    ClientHandler *c;
    bool stopServer = false;
    //TasksQueue *tasks;
   // queue<std::thread> *workers;
};

class MyParallelServer : public server_side::Server {
private:
    struct acceptInfo1 *info;
    void* acceptClients(void* args);
public:
    MyParallelServer() {
        this->info = new acceptInfo1();

    }

    void open(int port, ClientHandler *c) override ;

    virtual void stop() override ;

    ~MyParallelServer() override {}
};
#endif //MILESTONE_2_MYPARALLELSERVER_H
