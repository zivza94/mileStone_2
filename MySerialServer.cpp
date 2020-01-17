//
// Created by ziv on 13/01/2020.
//

#include <iostream>
#include "MySerialServer.h"

const int seconds_till_time_out = 30;
void MySerialServer::accept() {
    //making socket listen to the port
    if (listen(socketfd, 5) == -1) { //can also set to SOMAXCON (max connections)
        std::cerr<<"Error during listening command"<<std::endl;
        return;
    } else{
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    struct timeval tv;
    tv.tv_sec = seconds_till_time_out;
    // set each connection to socket to be 30 seconds.
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
    // keep going to handle more clients until stopServer boolean change to true from the function close
    while (!stopServer) {
        // accepting a client
        int clientSocket = ::accept(socketfd, (struct sockaddr *) &address,
                                     (socklen_t *) &address);

        if (clientSocket == -1) {
            std::cerr << "Error accepting client" << std::endl;
            return;
        }
        // handle the discussion with the client - send/recv
        c.handleClient(clientSocket);
    }
}
void MySerialServer::open(int port, ClientHandler clientHandler) {
    //create socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        std::cerr << "Could not create a socket"<<std::endl;
        return;
    }

    //bind socket to IP address
    address.sin_family = AF_INET;
    //give me any IP allocated for my machine
    address.sin_addr.s_addr = INADDR_ANY;
    // convert our number to a number that the network understands.
    address.sin_port = htons(port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        std::cerr<<"Could not bind the socket to an IP"<<std::endl;
        return;
    }

    thread t(&MySerialServer::accept, this);
    t.detach();
}

void MySerialServer::stop() {
    stopServer = 1;
    // close the option of new connetion to the server
    close(socketfd);
}

