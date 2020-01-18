//
// Created by ziv on 15/01/2020.
//

#ifndef MILESTONE_2_CACHEMANAGER_H
#define MILESTONE_2_CACHEMANAGER_H

#include <string>

using namespace std;
template <typename P, typename S>
class CacheManager {
public:
    virtual bool isExist(P problem) = 0;
    virtual string getSolution(P problem) = 0;
    virtual void saveSolution(P problem,S solution) = 0;

};
#endif //MILESTONE_2_CACHEMANAGER_H
