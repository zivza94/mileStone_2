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
    State<T> _comeFrom;
public:
    State(T state, double cost, State<T>* comeFrom = nullptr):_state(state), _cost(cost), _comeFrom(comeFrom){};
    bool operator==(const State<T>);
    T getState () {return _state;};
    double getCost() {return _cost;};
    State<T> getFather() { return _comeFrom;};

};

template<typename T>
bool State<T>::operator==(const State<T> s) {
    return _state.equals(s.state);
}

#endif //MILESTONE_2_STATE_H
