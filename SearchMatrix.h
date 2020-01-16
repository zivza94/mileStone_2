//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_SEARCHMATRIX_H
#define MILESTONE_2_SEARCHMATRIX_H
#include <string>
#include "Searchable.h"
#include "IntCell.h"

using namespace std;
//template <typename T>
class SearchMatrix : public Searchable<IntCell> {
private:
    list<IntCell> _mat;
    State<IntCell> _initState;
    State<IntCell> _goalState;
public:
    SearchMatrix(string mat, string startCell, string endCell);
    State<IntCell> getInitialState();
    bool isGoalState(State<IntCell> state);
    list<State<IntCell>> getAllPossibleStates(State<T> s);
};

SearchMatrix::SearchMatrix(string mat, string startCell, string endCell) {


}


State<T> SearchMatrix::getInitialState() {}

bool SearchMatrix::isGoalState(State<T> state) {}

list<State<T>> SearchMatrix<T>::getAllPossibleStates(State<T> s) {}


#endif //MILESTONE_2_SEARCHMATRIX_H
