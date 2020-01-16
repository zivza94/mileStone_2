//
// Created by ziv on 15/01/2020.
//

#include "Main.h"
#include "Solver.h"
#include "StringReverser.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "MySerialServer.h"

int boot::Main::main(int argc, string* argv) {
    int port = stoi(argv[0]);
    Solver<string,string>* solver = new StringReverser();
    CacheManager<string,string>* cache = new FileCacheManager();
    ClientHandler* handler = new MyTestClientHandler(solver, cache);
    server_side::Server* server = new MySerialServer();
    server->open(port, *handler);
    // when to stop




    
    return 0;

}