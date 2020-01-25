//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_BFS_H
#define MILESTONE_2_BFS_H

#include <map>
#include <unordered_map>
#include "Solution.h"
#include "Searcher.h"
#include "SearchAlgorithms.h"

template <typename T>
class BFS : public SearchAlgorithms<T> {
public:
    string search (Searchable<T>* s) override;


};
template <typename T>
string BFS<T>::search(Searchable<T>* s) {
    State<T>* v = s->getInitialState();
    map<State<T>*,bool> visited;
    list<State<T>*> queue;
    queue.push_back(v);
    // while there is still state we didnt visited
    while(!queue.empty()){
        this->evaluated++;
        v = queue.front();
        queue.pop_front();
        // if we found the end path
        if (s->isGoalState(v)){
            //impl getSolution(s,v)
            return this->getSolution(s,v);
        }
        //get all the possible states
        list<State<T>*> possibleStates = s->getAllPossibleStates(v);
        while(!possibleStates.empty()){
            State<T>* state = possibleStates.front();
            possibleStates.pop_front();
            bool visit = !(visited.find(state) == visited.end());
            //if we didnt visited the cell
            if (!visit){

                queue.push_back(state);
                visited[state] = true;
                state->setComeFrom(v);
                state->setCost(v->getCost() + state->getState()->getValue());
            }
        }
    }
    // no path found
    return "no path to goal state";
}

#endif //MILESTONE_2_BFS_H