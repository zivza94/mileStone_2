//
// Created by liza on 16/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int clientSocket) {
    char buffer[1024] = {0};
    //reading from client
    int valread = read(clientSocket, buffer, 1024);
    if (valread <= 0) {
        return;
    }
    cout << buffer << endl;
    //writing back to client
    char *hello = "Hello, I can hear you! \n";
    send(clientSocket, hello, strlen(hello), 0);
    std::cout << "Hello message sent\n" << std::endl;

}