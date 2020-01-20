//
// Created by liza on 16/01/2020.
//

#include "MyTestClientHandler.h"

void MyTestClientHandler::handleClient(int clientSocket) {
    string problem;
    char buffer[512];
    char* space = "\n";
    while (strcmp(buffer, "end") != 0) {
        //reset the buffer
        memset(buffer, 0, 512) ;
        //reading from client
        int valread = read(clientSocket, buffer, 512);
        if (valread <= 0) {
            return;
        }
        cout << buffer << endl;
        string retStr;
        // send using the solver
        if (cm->isExist(buffer)) {
            retStr = cm->getSolution(buffer);
        } else {
            retStr = solver->solve(buffer);
            cm->saveSolution(buffer, retStr);
        }
        //writing back to client
        send(clientSocket, retStr.c_str(), retStr.length(), 0);
        send(clientSocket, space, 2, 0);

    }
}