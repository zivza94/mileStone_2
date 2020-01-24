//
// Created by liza on 20/01/2020.
//

#include "MyClientHandler.h"

void MyClientHandler::handleClient(int clientSocket) {
    string problem = "";
    char buffer[512];
    char* solution;
    while (true) {
        // reset the buffer
      //  memset(buffer, 0, 512) ;
        //reading from client
        int valread = read(clientSocket, buffer, 512);
        if (valread <= 0) {
            return;
        }
        // check
     //   cout << buffer << endl;
        if (strcmp(buffer, "end") == 0) {
            break;
        }
        problem += buffer;
        problem += '\n';
    }
    string retStr;
    if (cm->isExist(problem)) {
        retStr = cm->getSolution(problem);
    } else {
        retStr = solver->solve(problem);
        cm->saveSolution(problem, retStr);
        retStr += '\n';
    }
    //writing to the client the solution
    send(clientSocket, retStr.c_str(), retStr.length(), 0);
    cout <<retStr << endl;
}