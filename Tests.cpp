//
// Created by ziv on 15/01/2020.
//
#include <string>
#include <iostream>
#include "StringReverser.h"
#include "SearchMatrix.h"
#include "BFS.h"

using namespace std;
class Tests{
    void checkStringReverser(){
        string str= "abcdefg";
        string expected = "gfedcba";
        Solver<string,string>* reverser = new StringReverser();
        string actual = reverser->solve(str);
        if(actual == expected){
            cout<< "StringReverser.Solve(problem) work propertly"<<endl;
        } else {
            cout<< "StringReverser.solve(problem) doesn't work"<<endl;
            cout<< "expected: " + expected + "actual: " + actual<<endl;
        }
        return;
    }

    void checkBuildMatrix(){
       /* //test matrix of 2 on 2
        string matAsString = "8,5,7\n6,3,4\n1,4,3\n0,0\n2,2";
        Searchable<Cell>* mat = new SearchMatrix(matAsString);
        // need to test manual*/
    }
    void checkGetSolution(){
        /*string matAsString = "8,5,7\n6,3,4\n1,4,3\n0,0\n2,2";
        Searchable<Cell>* mat = new SearchMatrix(matAsString);
        Searcher<Cell>* bfs = new BFS<Cell>();
        string answer = bfs->search(mat);
        cout<< answer<<endl;*/


    }

public:
    void tests() {

        checkBuildMatrix();
        checkStringReverser();
    }
};
