//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_SEARCHMATRIX_H
#define MILESTONE_2_SEARCHMATRIX_H
#include <string>
#include "Searchable.h"
#include "Cell.h"

using namespace std;
//template <typename T>
class SearchMatrix : public Searchable<Cell> {
private:
    list<Cell> _mat;
    State<Cell> _initState;
    State<Cell> _goalState;
public:
    SearchMatrix(string mat, string startCell, string endCell);
    State<Cell> getInitialState();
    bool isGoalState(State<Cell> state);
    list<State<Cell>> getAllPossibleStates(State<T> s);
};

SearchMatrix::SearchMatrix(string mat, string startCell, string endCell) {
    //split the mat to cells with cost.

    //initCell = startCell -->> cell

    //goalCell = endCell -->> cell

}
State<Cell> SearchMatrix::getInitialState() {
    return _initState;
}

bool SearchMatrix::isGoalState(State<Cell> state) {
    return _goalState == state;
}

list<State<Cell>> SearchMatrix::getAllPossibleStates(State<T> s) {
    list<Cell> retval = new list<Cell>();
    // if !end of row/col
    // add to retval

    //if !cost of next s == infinity
    // add to retval
}


State<T> SearchMatrix::getInitialState() {}

bool SearchMatrix::isGoalState(State<T> state) {}

list<State<T>> SearchMatrix<T>::getAllPossibleStates(State<T> s) {}


#endif //MILESTONE_2_SEARCHMATRIX_H
