cmake_minimum_required(VERSION 3.15)
project(mileStone_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(mileStone_2 main.cpp Server.h MySerialServer.cpp MySerialServer.h Solver.h StringReverser.cpp StringReverser.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Main.cpp Main.h Tests.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Searcher.h Searchable.h State.cpp State.h Cell.cpp Cell.h Solution.cpp Solution.h SearchMatrix.h BFS.cpp BFS.h CHECKFORGIT.h)