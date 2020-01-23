//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_STATE_H
#define MILESTONE_2_STATE_H

#include <clocale>

template< typename T>
class State {
private:
    T _state;
    int _cost;
    State<T>* _comeFrom;
    int _heuristic;
public:
    State(T state, double cost, State<T>* comeFrom = NULL):_state(state), _cost(cost), _comeFrom(comeFrom){};
    bool operator==(const State<T>);
    //getters
    T getState () {return _state;};
    int getCost() {return _cost;};
    State<T>* getComeFrom() { return _comeFrom;};
    int getHeuristic();

    //setters
    void setState(T state) {_state = state;};
    void setCost(int cost){ _cost = cost;};
    void setComeFrom(State<T>* comeFrom) {_comeFrom = comeFrom;};
    void setHeuristic(int heuristic){ _heuristic = heuristic;};
};

template<typename T>
bool State<T>::operator==( State<T> s) {
    return _state == s.getState();
}

#endif //MILESTONE_2_STATE_H
