//
// Created by ziv on 22/01/2020.
//

#ifndef MILESTONE_2_ASTAR_H
#define MILESTONE_2_ASTAR_H

#include <cmath>
#include "SearchAlgorithms.h"
#include "DistanceComperator.h"
#include <queue>
template< typename T>
class AStar : public SearchAlgorithms<T> {
private:
    bool isOpen(State<T>* state, priority_queue <State<T>*, vector<State<T>*>, DistanceComperator>);
public:
    string search (Searchable<T>* s) override;
};
template<typename T>
bool AStar<T>::isOpen(State<T> *state, priority_queue<State<T> *, vector<State<T> *>, DistanceComperator> open) {
    // check if the state in the open list
    bool retval = false;
    vector<State<T>*> tempVector;
    State<T>* tempState;
    // pop from open and push in temporary vector to storw
    while(!open.empty()){
        tempState = open.top();
        // check if this is the state
        if(tempState == state){
            retval = true;
            break;
        }
        tempVector.push_back(tempState);
        open.pop();
    }
    // push back to the priority queue
    while(!tempVector.empty()){
        tempState = tempVector.back();
        open.push(tempState);
        tempVector.pop_back();
    }
    return retval;
}

template<typename T>
string AStar<T>::search(Searchable<T> *s) {
    //priority queue based on cost and heuristic
    priority_queue <State<T>*, vector<State<T>*>, DistanceComperator> openQueue;
    vector<State<T>*> closeQueue;
    //start from the init state
    State<T>* start = s->getInitialState();
    openQueue.push(start);
    while(!openQueue.empty()){
        // get the state with the lowest cost+heuristic
        State<T>* state = openQueue.top();
        this->evaluated++;
        openQueue.pop();
        if(s->isGoalState(state)){
            // found goal state
            return this->getSolution(s, state);
        }
        // get all possibale states from state
        list<State<T>*> possibleStates = s->getAllPossibleStates(state);
        while(!possibleStates.empty()){
            State<T>* v = possibleStates.front();

            possibleStates.pop_front();
            int currentCost = state->getCost() + v->getState()->getValue();
            // if the state in open
            if(isOpen(v,openQueue)){
                if(v->getCost() <= currentCost){
                    continue;
                }
                //update the state
                v->setCost(currentCost);
                v->setComeFrom(state);
            } else if (this->isClose(v,closeQueue)){
                //if the state in close
                if(v->getCost() <= currentCost){
                    continue;
                }
                // remove from close and move to open
                this->removeFromClose(v,closeQueue);
                //update the state
                v->setCost(currentCost);
                v->setComeFrom(state);
                openQueue.push(v);
            } else {
                // if we didnt visited the state
                //update the state
                v->setCost(currentCost);
                v->setComeFrom(state);
                openQueue.push(v);
            }
        }
        // move the state to close
        closeQueue.push_back(state);
    }
    //no path found
    return "no path to goal state";
}

#endif //MILESTONE_2_ASTAR_H
