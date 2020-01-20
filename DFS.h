//
// Created by liza on 20/01/2020.
//

#ifndef MILESTONE_2_DFS_H
#define MILESTONE_2_DFS_H

#include "Searcher.h"
#include "Solution.h"
#include <map>

template <typename T>
class DFS : public Searcher<T> {
    Solution search (Searchable<T> s) override;

};


#endif //MILESTONE_2_DFS_H
