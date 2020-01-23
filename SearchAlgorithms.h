//
// Created by ziv on 21/01/2020.
//

#ifndef MILESTONE_2_SEARCHALGORITHMS_H
#define MILESTONE_2_SEARCHALGORITHMS_H
#include <list>
#include "Searcher.h"

template <typename T>
class SearchAlgorithms: public Searcher<T> {
protected:
    int evaluated = 0;
public:
    virtual string search (Searchable<T>* s) = 0;
    virtual string getSolution(Searchable<T>* s,State<T>* goalState);
    virtual int getEvaluated(){return evaluated;};

};

template <typename  T>
string SearchAlgorithms<T>::getSolution(Searchable<T>* s,State<T>* goalState) {
    list<string> path;
    string answer;
    State<T>* state = goalState;
    while ((state != s->getInitialState())){
        State<T>* comeFrom = state->getComeFrom();
        int ansRow = comeFrom->getState()->getRow();
        int ansCol = comeFrom->getState()->getCol();
        int sRow = state->getState()->getRow();
        int sCol = state->getState()->getCol();
        if(sRow > ansRow){
            path.push_front("Down (" + to_string(state->getCost()) + "),");
        }else if(sCol > ansCol){
            path.push_front("Right (" + to_string(state->getCost()) + "),");
        }else if(sRow < ansRow){
            path.push_front("Up (" + to_string(state->getCost()) + "),");
        }else if(sCol < ansCol){
            path.push_front("Left (" + to_string(state->getCost()) + "),");
        }
        state = comeFrom;

    }
    while (!path.empty()){
        answer += path.front();
        path.pop_front();

    }

    return answer;
}


#endif //MILESTONE_2_SEARCHALGORITHMS_H