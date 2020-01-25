//
// Created by liza on 20/01/2020.
//

#include <thread>
#include "MyClientHandler.h"

void MyClientHandler::handleClient(int clientSocket) {
    //cout<<"start thread"<< this_thread::get_id()<<endl;
    string problem = "";
    char buffer[512];
    char *solution;
    while (true) {
        // reset the buffer
        memset(buffer, 0, 512);
        //reading from client
        int valread = read(clientSocket, buffer, 512);
        if (valread <= 0) {
            return;
        }
        int length = strlen(buffer) - 1;
        if (buffer[length] == '\n') {
            buffer[length] = 0;
        }

        if (strcmp(buffer, "end") == 0) {
            break;
        }
        // add the line to the problem
        problem += buffer;
        problem += '\n';
    }
    string retStr;
    // search in the cacheManager
    if (cm->isExist(problem)) {
        retStr = cm->getSolution(problem);
    } else {
        // solve the problem and save in cache manager
        retStr = solver->solve(problem);
        cm->saveSolution(problem, retStr);
        retStr += '\n';
    }
    //writing to the client the solution
    send(clientSocket, retStr.c_str(), retStr.length(), 0);
}