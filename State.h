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
    double _cost;
    State<T>* _comeFrom;
    bool visited = false;
public:
    State(T state, double cost, State<T>* comeFrom = NULL):_state(state), _cost(cost), _comeFrom(comeFrom){};
    bool operator==(const State<T>);
    //getters
    T getState () {return _state;};
    double getCost() {return _cost;};
    State<T>* getComeFrom() { return _comeFrom;};

    //setters
    void setState(T state) {_state = state;};
    void setCost(double cost){ _cost = cost;};
    void setComeFrom(State<T>* comeFrom) {_comeFrom = comeFrom;};
};

template<typename T>
bool State<T>::operator==( State<T> s) {
    return _state == s.getState();
}

#endif //MILESTONE_2_STATE_H
