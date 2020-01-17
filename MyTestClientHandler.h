//
// Created by liza on 16/01/2020.
//

#ifndef MILESTONE_2_MYTESTCLIENTHANDLER_H
#define MILESTONE_2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

template <typename P, typename S>
class MyTestClientHandler : public virtual ClientHandler {
private:
    Solver<P,S> solver;
    CacheManager<P,S> cm;
public:
    MyTestClientHandler(Solver<P,S> s ,CacheManager<P,S> cache) {
        solver = s;
        cm = cache;
    }
    void handleClient(int clientSocket);
};
#endif //MILESTONE_2_MYTESTCLIENTHANDLER_H
