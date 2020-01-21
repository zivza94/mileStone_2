//
// Created by liza on 20/01/2020.
//

#include "DFS.h"

enum Colored {
    grey,
    black
};
template <typename T>
string DFS<T>::search(Searchable<T>* s) {
    map<State<T>*, bool> visited = new map<T*, bool>();
    stack <State<T>*> stack;
    State<T>* v = s->getInitialState();
    stack.push(v);
    while (!stack.empty()) {
        v = stack.top();
        stack.pop();
        // if we found the end path
        if (s->isGoalState(*v)) {
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
}

/*
    map<State<T>*,Colored> color = new map<T,Colored >();
    State<T>* v = s->getInitialState();
    color.insert(pair<State<T>,Colored>(v, grey));
    if (s->isGoalState(v)) {
        // Implement get path
        return getSolution(s,v);
    }
    list<State<T>> neighbors = s->getAllPossibleStates(v);
    typename list<State<T>*>::iterator it;
    for (it = neighbors.begin(); it != neighbors.end(); it ++) {
        // if the vertx isn't colored yet continue the search on him
        if (color.find(*it) == color.end()) {
        }
    }
    map<State<T>*, bool> visited = new map<T*, bool>();
    stack <State<T>*> stack;
    State<T>* initial = s->getInitialState();
    stack.push(initial);
    // ADD the first vertex to the visited nodes
    visited.insert(pair<State<T>*, bool>(initial, true));
    while (!stack.empty()) {
        State<T>* parent = stack.top();
        list<State<T>*> neighbors = s->getAllPossibleStates(parent);
        typename list<State<T>*>::iterator it;
        for (it = neighbors.begin(); it != neighbors.end(); it ++) {
            // if the neighbor hasn't visited yet add him to the stack
            if (visited.find(*it) != visited) {
                stack.push(*it);

            }
        }
    }
     */