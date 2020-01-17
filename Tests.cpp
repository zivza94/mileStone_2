//
// Created by ziv on 15/01/2020.
//
#include <string>
#include <iostream>
#include "StringReverser.h"

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

public:
    void tests() {
        checkStringReverser();
    }
};
