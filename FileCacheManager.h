//
// Created by ziv on 15/01/2020.
//

#ifndef MILESTONE_2_FILECACHEMANAGER_H
#define MILESTONE_2_FILECACHEMANAGER_H
#include <string>
#include <map>
#include "CacheManager.h"
using namespace std;
class FileCacheManager : public CacheManager<string,string> {
private:
    map<string, bool> solutionExist;
public:
    bool isExist(string problem);
    string getSolution(string problem);
    void saveSolution(string problem,string solution);
};


#endif //MILESTONE_2_FILECACHEMANAGER_H
