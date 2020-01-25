//
// Created by ziv on 15/01/2020.
//

#include <list>
#include <unordered_map>
#include <string>
#include <iostream>
#include <mutex>
#include "FileCacheManager.h"

mutex Mutex_lock_cache;
mutex Mutex_lock_files;
void FileCacheManager::saveSolution(string problem, string solution) {
    // not in the cache
    //lock the cache
    Mutex_lock_cache.lock();
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
    //unlock the cache
    Mutex_lock_cache.unlock();

    //lock the files
    Mutex_lock_files.lock();
    //open file
    fstream fp (to_string(hashFunc(problem)) + ".txt",ios::out) ;
    //write to file
    fp.write(solution.c_str(),solution.length());
    fp.close();
    //unlock the files
    Mutex_lock_files.unlock();
}


string FileCacheManager::getSolution(string problem) {
    //lock the cache
    Mutex_lock_cache.lock();
    if(cache.find(problem) != cache.end()){
        auto pair = cache[problem];
        lru_list.erase(pair.second);
        lru_list.push_front(problem);
        pair = {pair.first, lru_list.begin()};
        //cache.erase(key);
        cache[problem] = pair;
        string solution =  cache[problem].first;
        // unlock the cache
        Mutex_lock_cache.unlock();
        return solution;
    } else {
        //unlock the cache
        Mutex_lock_cache.unlock();
        // lock the files
        Mutex_lock_files.lock();
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
        // unlock the files
        Mutex_lock_files.unlock();
        // lock the cache
        Mutex_lock_cache.lock();
        if(!lru_list.empty()){
            string last = lru_list.back();
            lru_list.pop_back();
            cache.erase(last);
        }
        lru_list.push_front(problem);
        cache[problem] = {solution, lru_list.begin()};
        //unlock the cache
        Mutex_lock_cache.unlock();
        return solution;
    }
}
bool FileCacheManager::isExist(string problem){
    bool retval = true;
    //lock the file
    Mutex_lock_files.lock();
    //search if there is file for the problem
    fstream fp (to_string(hashFunc(problem)) + ".txt", ios::in);
    if( !fp.is_open()) {
        retval = false;
    }
    // close the file
    fp.close();
    // unlock the files
    Mutex_lock_files.unlock();
    return retval;
}



