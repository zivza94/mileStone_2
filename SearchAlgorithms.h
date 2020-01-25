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
    virtual bool isClose(State<T>* state, vector<State<T>*> close);
    virtual void removeFromClose(State<T>* state,vector<State<T>*> close);
    virtual ~SearchAlgorithms(){};

};

template <typename  T>
string SearchAlgorithms<T>::getSolution(Searchable<T>* s,State<T>* goalState) {
    // return the solution
    list<string> path;
    string answer;
    State<T>* state = goalState;
    //start from the goal state and add the father and the cost
    while ((state != s->getInitialState())){
        State<T>* comeFrom = state->getComeFrom();
        int ansRow = comeFrom->getState()->getRow();
        int ansCol = comeFrom->getState()->getCol();
        int sRow = state->getState()->getRow();
        int sCol = state->getState()->getCol();
        if(sRow > ansRow){
            path.push_front("Down (" + to_string(state->getCost()) + "), ");
        }else if(sCol > ansCol){
            path.push_front("Right (" + to_string(state->getCost()) + "), ");
        }else if(sRow < ansRow){
            path.push_front("Up (" + to_string(state->getCost()) + "), ");
        }else if(sCol < ansCol){
            path.push_front("Left (" + to_string(state->getCost()) + "), ");
        }
        state = comeFrom;

    }
    // add to string from the start to the goal state
    while (!path.empty()){
        answer += path.front();
        path.pop_front();

    }
    answer = answer.substr(0,answer.length() - 2);

    return answer;
}

template<typename T>
bool SearchAlgorithms<T>::isClose(State<T>* state, vector<State<T>*> close){
    // check if the state in the close queue
    int i;
    for (i = 0; i<close.size(); i++){
        if(state == close[i]){
            return true;
        }
    }
    return false;
}
template<typename T>
void SearchAlgorithms<T>::removeFromClose(State<T>* state,vector<State<T>*> close){
    //remove the state from the close queue
    typename vector<State<T>*>::iterator it;
    for (it = close.begin(); it != close.end(); it++){
        if(*it == state){
            close.erase(it);
            return;
        }
    }
    return;
}
#endif //MILESTONE_2_SEARCHALGORITHMS_H