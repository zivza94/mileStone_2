//
// Created by liza on 23/01/2020.
//

#ifndef MILESTONE_2_COSTCOMPERATOR_H
#define MILESTONE_2_COSTCOMPERATOR_H

#include "State.h"

template <typename T>
class CostComperator {
public:
    bool operator()(const State<T> a, const State<T> b) {
        return a.getCost() > b.getCost();
    }
};


#endif //MILESTONE_2_COSTCOMPERATOR_H
