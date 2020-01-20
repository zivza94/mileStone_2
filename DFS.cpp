//
// Created by liza on 20/01/2020.
//

#include "DFS.h"

enum Colored {
    grey,
    black
};
template <typename T>
Solution DFS<T>::search(Searchable<T> s) {
    map<State<T>,Colored> color = new map<T,Colored >();
    State<T> v = s.getInitialState();
    color.insert(pair<State<T>,Colored>(v, grey));


}
