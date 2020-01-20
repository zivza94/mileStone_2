//
// Created by ziv on 13/01/2020.
//

#ifndef MILESTONE_2_MYSERIALSERVER_H
#define MILESTONE_2_MYSERIALSERVER_H


#include "Server.h"

struct acceptInfo {
    int port;
    ClientHandler *c;
    bool stopServer = false;
};

class MySerialServer : public server_side::Server {
    private:
        struct acceptInfo *info;
    public:
        MySerialServer() {
            this->info = new acceptInfo();
        }

        void open(int port, ClientHandler *c) override ;

        virtual void stop() override ;

        ~MySerialServer() override {}
    };
#endif //MILESTONE_2_MYSERIALSERVER_H
