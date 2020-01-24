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

template<typename T>
string AStar<T>::search(Searchable<T> *s) {
    //int flag = 1;
    priority_queue <State<T>*, vector<State<T>*>, DistanceComperator> openQueue;
    vector<State<T>*> closeQueue;
    State<T>* start = s->getInitialState();
    openQueue.push(start);
    while(!openQueue.empty()){

        State<T>* state = openQueue.top();
        this->evaluated++;
        openQueue.pop();
        if(s->isGoalState(state)){
            return this->getSolution(s, state);
        }
        list<State<T>*> possibleStates = s->getAllPossibleStates(state);
        while(!possibleStates.empty()){
            State<T>* v = possibleStates.front();

            possibleStates.pop_front();
            int currentCost = state->getCost() + v->getState()->getValue();
            if(isOpen(v,openQueue)){
                if(v->getCost() <= currentCost){
                    continue;
                }
                v->setCost(currentCost);
                v->setComeFrom(state);
            } else if (this->isClose(v,closeQueue)){
                if(v->getCost() <= currentCost){
                    continue;
                }
                this->removeFromClose(v,closeQueue);
                //flag = 1;
                v->setCost(currentCost);
                v->setComeFrom(state);
                openQueue.push(v);
            } else {
                //flag = 1;
                v->setCost(currentCost);
                v->setComeFrom(state);
                openQueue.push(v);
            }
            /*if(flag == 1) {
                flag = 0;
            } else {
                v->setCost(currentCost);
                v->setComeFrom(state);
            }*/
        }

        closeQueue.push_back(state);
    }
}

#endif //MILESTONE_2_ASTAR_H
