//
// Created by ziv on 13/01/2020.
//

#ifndef MILESTONE_2_MYSERIALSERVER_H
#define MILESTONE_2_MYSERIALSERVER_H


#include "Server.h"

class MySerialServer : public server_side::Server {
private:

    sockaddr_in address;
    int port, socketfd;
    ClientHandler c;
    bool stopServer = 0;
    void accept();
public:
    void open (int port,ClientHandler c);
    void stop ();
};


#endif //MILESTONE_2_MYSERIALSERVER_H
