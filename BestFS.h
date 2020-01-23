//
// Created by liza on 23/01/2020.
//

#ifndef MILESTONE_2_BESTFS_H
#define MILESTONE_2_BESTFS_H


#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include "Solution.h"
#include "Searcher.h"
#include "SearchAlgorithms.h"
#include "CostComperator.h"

template <typename T>
class BestFS : public SearchAlgorithms<T> {
public:
    string search (Searchable<T>* s) override;


};
template <typename T>
string BestFS<T>::search(Searchable<T>* s) {
    State<T>* v = s->getInitialState();
    priority_queue<State<T>, vector<State<T>>, CostComperator<T> > open;
    list<State<T>*> closed;

    open.push(v);
    while(!open.empty()){
        v = open.top();
        // remove the best state from open and transfer him to close
        open.pop();
        closed.add(v);
        // if we found the end path
        if (s->isGoalState(v)){
            //impl getSolution(s,v)
            return this->getSolution(s,v);
        }
        // get all the neighbors of v
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



#endif //MILESTONE_2_BESTFS_H
