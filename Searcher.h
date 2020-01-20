//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_SEARCHER_H
#define MILESTONE_2_SEARCHER_H

#include "Searchable.h"
#include "Solution.h"

template <typename T>
class Searcher {
    virtual Solution search (Searchable<T> s) = 0;

};
#endif //MILESTONE_2_SEARCHER_H
