//
// Created by liza on 23/01/2020.
//

#ifndef MILESTONE_2_BESTFS_H
#define MILESTONE_2_BESTFS_H


#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include "Solution.h"
#include "Searcher.h"
#include "SearchAlgorithms.h"
#include "CostComperator.h"

template <typename T>
class BestFS : public SearchAlgorithms<T> {
private:
    // function for check only
    //void showpq(priority_queue<State<T> *, vector<State<T> *>, CostComperator> gq);
    bool isOpen(State<T>* state, priority_queue <State<T>*, vector<State<T>*>, CostComperator> open);
public:
    string search (Searchable<T>* s) override;
};

template <typename T>
string BestFS<T>::search(Searchable<T>* s) {
    State<T>* v = s->getInitialState();
    priority_queue <State<T>*, vector<State<T>*>, CostComperator> open;
    vector<State<T>*> closed;

    open.push(v);
    while(!open.empty()){
        v = open.top();
        this->evaluated++;
        // remove the best state from open and transfer him to close
        open.pop();
        closed.push_back(v);
        // if we found the end path
        if (s->isGoalState(v)){
            //impl getSolution(s,v)
            return this->getSolution(s,v);
        }
        // get all the neighbors of v
        list<State<T>*> possibleStates = s->getAllPossibleStates(v);
        // iterate over all the neighbors
        while(!possibleStates.empty()) {
            State<T>* state = possibleStates.front();
            possibleStates.pop_front();
            // check if the vertex is in one of the max(it can be either there or there or nun)
            bool inOpen = isOpen(state,open);
            bool inClosed = this->isClose(state, closed);
            if (!inClosed && !inOpen) {
                state->setComeFrom(v);
                state->setCost(v->getCost() + state->getState()->getValue());
                open.push(state);
            }
        }
       // showpq(open);
    }
    //no path found
    return "no path to goal state";
}

template<typename T>
bool BestFS<T>::isOpen(State<T>* state, priority_queue<State<T>*, vector<State<T> *>, CostComperator> open) {
    bool retval = false;
    vector<State<T>*> tempVector;
    State<T>* tempState;
    while(!open.empty()){
        tempState = open.top();
        if(tempState == state){
            retval = true;
            break;
        }
        tempVector.push_back(tempState);
        open.pop();
    }

    while(!tempVector.empty()){
        tempState = tempVector.back();
        open.push(tempState);
        tempVector.pop_back();
    }
    return retval;
}

/*
template<typename T>
void BestFS<T>::showpq(priority_queue<State<T> *, vector<State<T> *>, CostComperator> gq) {
    priority_queue<State<T> *, vector<State<T> *>, CostComperator> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}
*/
#endif //MILESTONE_2_BESTFS_H
