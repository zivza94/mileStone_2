//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_SEARCHABLE_H
#define MILESTONE_2_SEARCHABLE_H
#include <list>
#include "State.h"
using namespace std;
template <typename T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual bool isGoalState(State<T>* state) = 0;
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) = 0;
    virtual int getHeuristicSearch(State<T>* state) = 0;
};
#endif //MILESTONE_2_SEARCHABLE_H
