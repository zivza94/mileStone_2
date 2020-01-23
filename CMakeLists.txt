cmake_minimum_required(VERSION 3.15)
project(mileStone_2)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

add_executable(mileStone_2 main.cpp Server.h MySerialServer.cpp MySerialServer.h Solver.h StringReverser.cpp StringReverser.h CacheManager.h FileCacheManager.cpp FileCacheManager.h Tests.cpp ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Searcher.h Searchable.h State.h Cell.cpp Cell.h Solution.cpp Solution.h SearchMatrix.h BFS.h Main.h DFS.h MyClientHandler.cpp MyClientHandler.h SearchMatrix.cpp SearchAlgorithms.cpp SearchAlgorithms.h SolverQA.cpp SolverQA.h MyParallelServer.cpp MyParallelServer.h BestFS.h CostComperator.h)