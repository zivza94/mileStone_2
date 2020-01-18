//
// Created by liza on 16/01/2020.
//

#ifndef MILESTONE_2_MYTESTCLIENTHANDLER_H
#define MILESTONE_2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    Solver<string,string>* solver;
    CacheManager<string,string>* cm;
public:
    MyTestClientHandler(Solver<string,string>* s ,CacheManager<string,string>* cache) {
        this->solver = s;
        this->cm = cache;
    }
    void handleClient(int clientSocket) override;
     ~MyTestClientHandler() override{}
};
#endif //MILESTONE_2_MYTESTCLIENTHANDLER_H
