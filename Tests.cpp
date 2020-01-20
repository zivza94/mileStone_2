//
// Created by ziv on 15/01/2020.
//
#include <string>
#include <iostream>
#include "StringReverser.h"
#include "SearchMatrix.h"
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
        string matAsString = "8,2,8,6,8,2,12,2,4,1,9,9,5,12,1,1,1,2,7,3,1,6,9,3,9,7,7,9,5,6,4,5,1,6,-1,1,7\n4,12,2,3,2,5,2,1,12,2,4,5,4,3,3,4,12,2,3,9,6,9,1,6,7,7,5,8,7,2,-1,3,2,5,-1,9,2\n1, 5, 8, 9, 2, 1, 2, 4, 7, 8, 2, 9, 8, 4, 2, 2,12, 8, 8, 2, 3, 3, 1, 5,12,-1, 2, 7, 1, 4,-1,-1,-1, 2,-1, 5, 6\n0,0\n3,10";
        Searchable<Cell>* mat = new SearchMatrix(matAsString);

    }


public:
    void tests() {

        checkBuildMatrix();
        checkStringReverser();
    }
};
