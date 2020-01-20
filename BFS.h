//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_BFS_H
#define MILESTONE_2_BFS_H

#include <map>
#include "Solution.h"
#include "Searcher.h"

template <typename T>
class BFS : public Searcher<T> {
    Solution search (Searchable<T> s) override;

};
template <typename T>
Solution BFS<T>::search(Searchable<T> s) {
    State<T> v = s.getInitialState();
    map<State<T>,bool> visited = new map<T,bool>();
    list<State<T>> queue;
    queue.push_back(v);

    while(!queue.empty()){
        v = queue.front();
        queue.pop_front();
        list<State<T>> possibleStates = s.getAllPossibleStates(v);
        typename list<State<T>>::iterator it;
        if (s.isGoalState(v)){
            //impl getSolution(s,v)
            return getSolution(s,v);
        }
        for (it = possibleStates.begin(); it != possibleStates.end(); it ++){
            if (visited.find(*it) == visited.end()){
                queue.push_back(*it);
                visited[*it] = true;
                *it.setFather(v);
            }
        }

    }
}


#endif //MILESTONE_2_BFS_H
