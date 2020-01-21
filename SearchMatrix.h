//
// Created by ziv on 16/01/2020.
//

//
//need to check if work
//add test to tests
//

#ifndef MILESTONE_2_SEARCHMATRIX_H
#define MILESTONE_2_SEARCHMATRIX_H
#include <string>
#include <iostream>
#include <vector>
#include "Searchable.h"
#include "Cell.h"
#include "State.h"

using namespace std;
class SearchMatrix : public Searchable<Cell*> {
private:
    int _size;
    vector<vector<pair<Cell*,State<Cell*>*>>> _mat;
    State<Cell*>* _initState;
    State<Cell*>* _goalState;

    vector<pair<Cell*,State<Cell*>*>> splitLineToCells(string, int row);
    list<string> splitProblemToMatrix(string problem);
    State<Cell*>* getState(State<Cell*>*,Cell*);
public:
    SearchMatrix(string problem);
    State<Cell*>* getInitialState();
    bool isGoalState(State<Cell*> state);
    list<State<Cell*>*> getAllPossibleStates(State<Cell*>* s);
     ~SearchMatrix();
};




#endif //MILESTONE_2_SEARCHMATRIX_H
