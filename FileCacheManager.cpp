//
// Created by ziv on 15/01/2020.
//

#include <list>
#include <unordered_map>
#include <string>
#include <iostream>

#include "FileCacheManager.h"


void FileCacheManager::saveSolution(string problem, string solution) {
    // not in the cache
    //string p = getProblemAsString(problem);
    if (cache.find(problem) == cache.end()) {
        //remove the last of the list and cache
        if (lru_list.size() == (unsigned int) capacity) {
            //remove from cache and list the lru.
            auto last = lru_list.back();
            lru_list.pop_back();
            cache.erase(last);
        }
    }
        // in cache.
    else {
        lru_list.erase(cache[problem].second);
        cache.erase(problem);
    }
    //add to the front of list and cache
    lru_list.push_front(problem);
    std::pair<string,list<string>::iterator> pair;
    pair.first = solution;
    pair.second = lru_list.begin();
    cache[problem] = pair;
    //open file
    fstream fp (to_string(hashFunc(problem)) + ".txt",ios::out) ;
    //write to file
    fp.write(solution.c_str(),solution.length());
    fp.close();
}


string FileCacheManager::getSolution(string problem) {
    //string p = getProblemAsString(problem);
    if(cache.find(problem) != cache.end()){
        auto pair = cache[problem];
        lru_list.erase(pair.second);
        lru_list.push_front(problem);
        pair = {pair.first, lru_list.begin()};
        //cache.erase(key);
        cache[problem] = pair;
        return cache[problem].first;
    } else {
        fstream fp (to_string(hashFunc(problem)) + ".txt", ios::in);
        if( !fp.is_open()) {
            throw "error";
        }
        string solution = "";
        string line;
        while(getline(fp,line)){
            solution += line + "\n";
        }
        //fp.read((char*) &solution,sizeof(obj));
        fp.close();

        if(!lru_list.empty()){
            string last = lru_list.back();
            lru_list.pop_back();
            cache.erase(last);
        }
        lru_list.push_front(problem);
        cache[problem] = {solution, lru_list.begin()};
        return solution;
    }
}
bool FileCacheManager::isExist(string problem){
    //string p = getProblemAsString(problem);
    fstream fp (to_string(hashFunc(problem)) + ".txt", ios::in);
    if( !fp.is_open()) {
        return false;
    }
    fp.close();
    return true;
}

/*string FileCacheManager::getProblemAsString(string problem) {
    string retval = "";
    int n;
    while(!problem.empty()){
        retval += problem.front();
        problem.pop_front();
    }
}*/

