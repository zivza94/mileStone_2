//
// Created by liza on 22/01/2020.
//

#include "MyParallelServer.h"

// 2 minuets maximum waiting for client to connect
const int seconds_till_time_out = 120;
/*
void* accept(void* args) {
    struct acceptInfo *info = (acceptInfo*) args;
    sockaddr_in address;
    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        //error
        cerr << "Could not create a socket"<< endl;
        exit(1);
    }

    //bind socket to IP address
    address.sin_family = AF_INET;
    //give me any IP allocated for my machine
    address.sin_addr.s_addr = INADDR_ANY;
    // convert our number to a number that the network understands.
    address.sin_port = htons(info->port);

    //the actual bind command
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cerr<<"Could not bind the socket to an IP"<< endl;
        exit(1);
    }

    //making socket listen to the port
    if (listen(socketfd, 1) == -1) { //can also set to SOMAXCON (max connections)
        cerr<<"Error during listening command"<< endl;
        exit(1);
    } else{
        cout<<"Server is now listening ..." << endl;
    }
    struct timeval tv;
    tv.tv_sec = seconds_till_time_out;
    // set each connection to socket to be 30 seconds.
    setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));
    // keep going to handle more clients until stopServer boolean change to true from the function close
    while (!info->stopServer) {
        // accepting a client
        int clientSocket = accept(socketfd, (struct sockaddr *) &address,
                                  (socklen_t *) &address);

        if (clientSocket == -1) {
            if (errno == EWOULDBLOCK) {
                cout << "waiting for client have reached to timeout" << endl;
                exit(1);
            } else {
                perror("Error accepting client");
                exit(1);
            }
        }
        // handle the discussion with the client - send/recv
        info->c->handleClient(clientSocket);
    }
}
void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    // add the parameters for sending to the out side function accept
    this->info->port = port;
    this->info->c = clientHandler;
    pthread_t t;
    pthread_create(&t, nullptr, accept, this->info);
    //pthread_detach(t);
    void *status;
    pthread_join(t, &status);
}

void MyParallelServer::stop() {
    this->info->stopServer = true;
}

 */