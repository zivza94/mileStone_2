//
// Created by liza on 20/01/2020.
//

#include "MyClientHandler.h"

void MyClientHandler::handleClient(int clientSocket) {
    string problem;
    char buffer[1024];
    char* space = "\n";
    char* solution;
    while (true) {
        // reset the buffer
        memset(buffer, 0, 512) ;
        //reading from client
        int valread = read(clientSocket, buffer, 1024);
        if (valread <= 0) {
            return;
        }
        // check
        cout << buffer << endl;
        if (strcmp(buffer, "end") != 0) {

        }
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