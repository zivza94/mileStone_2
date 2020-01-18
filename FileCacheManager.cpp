//
// Created by ziv on 15/01/2020.
//

#include <fstream>
#include <iostream>
#include "FileCacheManager.h"

bool FileCacheManager::isExist(string problem) {
    bool retval = false;
    if ( solutionExist.find(problem) != solutionExist.end()){
        retval = true;
    }
    return retval;
}

string FileCacheManager::getSolution(string problem) {
    if(!isExist(problem)) {
        cout<< "problem isn't exist"<<endl;
        exit(1);
    }
    fstream fp (problem + ".txt", ios::in);
    string retval = "";
    string line;
    while(getline(fp,line)){
        retval += line + "\n";
    }
    //fp.read((char*) &retval, 200);
    fp.close();
    return retval;
}

void FileCacheManager::saveSolution(string problem, string solution) {
    fstream fp (problem + ".txt", ios::out);
    fp.write(solution.c_str(), solution.length());
    fp.close();
    solutionExist[problem] = true;
}