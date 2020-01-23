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

    while(!queue.empty()){
        v = queue.front();
        queue.pop_front();
        // if we found the end path
        if (s->isGoalState(v)){
            //impl getSolution(s,v)
            return this->getSolution(s,v);
        }
        //typename list<State<T>*>::iterator it;
        list<State<T>*> possibleStates = s->getAllPossibleStates(v);
        while(!possibleStates.empty()){
            State<T>* state = possibleStates.front();
            possibleStates.pop_front();
            bool visit = !(visited.find(state) == visited.end());
            if (!visit){
                queue.push_back(state);
                //visited.insert(std::pair<T,bool>(stateT,true));
                visited[state] = true;
                state->setComeFrom(v);
                state->setCost(v->getCost() + state->getState()->getValue());
            }
        }
    }
}

#endif //MILESTONE_2_BFS_H