//
// Created by liza on 20/01/2020.
//

#ifndef MILESTONE_2_MYCLIENTHANDLER_H
#define MILESTONE_2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyClientHandler : public ClientHandler {
private:
    Solver<string,string>* solver;
    CacheManager<string,string>* cm;
public:
    MyClientHandler(Solver<string,string>* s ,CacheManager<string,string>* cache) {
        this->solver = s;
        this->cm = cache;
    }
    void handleClient(int clientSocket) override;
    ~MyClientHandler() override{}
};

#endif //MILESTONE_2_MYCLIENTHANDLER_H
