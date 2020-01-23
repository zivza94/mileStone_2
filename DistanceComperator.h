//
// Created by ziv on 23/01/2020.
//

#ifndef MILESTONE_2_DISTANCECOMPERATOR_H
#define MILESTONE_2_DISTANCECOMPERATOR_H


#include "Cell.h"
#include "State.h"
class DistanceComperator {
    bool operator()(State<Cell*>* state1,State<Cell*>* state2){
        int f1 = state1->getCost() + state1->getHeuristic();
        int f2 = state2->getCost() + state2->getHeuristic();
        return f1 < f2;
    }
};


#endif //MILESTONE_2_DISTANCECOMPERATOR_H
