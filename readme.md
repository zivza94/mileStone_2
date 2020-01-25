**mileStone_2**

A project which handles a server who solving problems for a client.

**Description**

This project uses design patterns such as bridge, handles communication and architecture of client-server, uses data structures
and data base.
the server can handle many clients at the same time by using threads.
The project keep solid principles which means we can reuse the code for different problems. for example, we separated the implementation of the server from the way he handle the client, so in this way we can rewrite a client handler which his communicate in different way and use it with the same server. 
The client handler has a solver which used for solving a different problems, again we can write different solvers and implement the one we want. For example in our code we use an Object Adapter which inherit from solver and has an object who inherits from Searcher. This searcher get's a searcheable object and produce a solution.
The client handler also have a Cache Manager which used for saving solutions which already resolved and in this way we don't need to waste time for resolving it again.
In this part we used an SearchMatrix which is searchable and Astar algorithm which is a Search.
The main implements the project in this way :
**-** we have an SearchMatrix which is a searchable.
**-** Astar algorithm which is a Searcher who solves the problem of finding the best way to get from point A to point B in the SearchMatrix which using the matrix that the client sent.
**-** A FileCacheManager manager which is a CacheManager who saves the solutions in a file.
**-** MyClientHandler which is a ClientHandler who read's the matrix from the client and sending the path with weights from the start till the end.
**-** ParallelServer which is Server and handles many clients in the same time.

**Getting Started**
Write an client which sends to the server an matrix of N*N with numbers comma separated, then one line for the start point, one line for the end point and in the line the sentence 'end'.
For example:

3,4,1

-1,2,2

5,6,1

0,0

1,1

end

-1 means wall.

Then in open the terminal in the folder of the project and write the next commands:
**-** g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
**-** ./a.out 'PORT NUMBER'

and than apply clients with the same PORT NUMBER which will send the server the matrix and will get the best path in return.

**Authors**

Ziv Zaarur 
Liza Yemini
