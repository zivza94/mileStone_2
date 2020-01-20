//
// Created by ziv on 15/01/2020.
//

#ifndef MILESTONE_2_FILECACHEMANAGER_H
#define MILESTONE_2_FILECACHEMANAGER_H
#include <list>
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>
#include "CacheManager.h"
using namespace std;
class FileCacheManager : public CacheManager<string,string> {
private:
    list<string> lru_list;
    unordered_map <string, std::pair<string,list<string>::iterator>> cache;
    int capacity;
    hash<string> hashFunc;
public:
    FileCacheManager(int cap): capacity(cap){};
    bool isExist(string problem);
    string getSolution(string problem);
    void saveSolution(string problem,string solution);
    string getProblemAsString(string problem);
};


#endif //MILESTONE_2_FILECACHEMANAGER_H
