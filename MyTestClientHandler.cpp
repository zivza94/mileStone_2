//
// Created by liza on 16/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int clientSocket) {
    string problem;

    char buffer[1024] = {0};

    //reading from client
    int valread = read(clientSocket, buffer, 1024);
    if (valread <= 0) {
        return;
    }
    cout << buffer << endl;
    //cout<< problem<<endl;
    string retStr;
    // send using the solver
    if(cm->isExist(buffer)){
        retStr = cm->getSolution(buffer);
    } else {
        retStr = solver->solve(buffer);
        cm->saveSolution(buffer,retStr);
    }
    send(clientSocket, retStr.c_str(), retStr.length(), 0);
    //writing back to client

    //char *hello = "Hello, I can hear you! \n";
    //send(clientSocket, hello, strlen(hello), 0);
    std::cout << "Hello message sent\n" << std::endl;

}