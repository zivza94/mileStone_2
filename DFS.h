//
// Created by liza on 20/01/2020.
//

#ifndef MILESTONE_2_DFS_H
#define MILESTONE_2_DFS_H

#include "Searcher.h"
#include "Solution.h"
#include "SearchAlgorithms.h"
#include <map>
#include <stack>
#include <iterator>


template <typename T>
class DFS : public SearchAlgorithms<T> {
    string search (Searchable<T>* s) override;
    virtual ~DFS(){};
};

template <typename T>
string DFS<T>::search(Searchable<T>* s) {
    map<State<T>*,bool> visited;
    stack <State<T>*> stack;
    State<T>* v = s->getInitialState();
    stack.push(v);
    while (!stack.empty()) {
        this->evaluated++;
        v = stack.top();
        stack.pop();
        // if we found the end path
        if (s->isGoalState(v)) {
            return this->getSolution(s, v);
        }
        list<State<T> *> possibleStates = s->getAllPossibleStates(v);
        while (!possibleStates.empty()) {
            State<T> *state = possibleStates.front();
            possibleStates.pop_front();
            bool visit = !(visited.find(state) == visited.end());
            if (!visit) {
                stack.push(state);
                visited[state] = true;
                state->setComeFrom(v);
                state->setCost(v->getCost() + state->getState()->getValue());
            }
        }
    }
    return "no path to goal state";
}


#endif //MILESTONE_2_DFS_H
