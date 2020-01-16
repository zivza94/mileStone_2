//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_STATE_H
#define MILESTONE_2_STATE_H

template< typename T>
class State {
private:
    T state;
    double cost;
    State<T> comeFrom;
public:
    bool operator==(const State<T>);
};

template<typename T>
bool State<T>::operator==(const State<T> s) {
    return state.equals(s.state);
}


#endif //MILESTONE_2_STATE_H
