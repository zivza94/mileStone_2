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
using namespace std;
//template <typename T>
class SearchMatrix : public Searchable<Cell> {
private:
    int _size;
    vector<vector<Cell>> _mat;
    State<Cell> _initState;
    State<Cell> _goalState;
    vector<Cell> splitLineToCells(string, int row);
public:
    SearchMatrix(list<string> mat, string startCell, string endCell);
    State<Cell> getInitialState();
    bool isGoalState(State<Cell> state);
    list<State<Cell>> getAllPossibleStates(vector<State<Cell>> s);
};

vector<Cell> SearchMatrix::splitLineToCells(string line, int row) {
    vector<Cell> retval;
    int start = 0;
    int end = 0;
    if(line[line.size() - 1] != ','){
        line += ",";
    }
    end = line.find(',', start);
    while(end != -1) {
        Cell c = new Cell(row, end%2,stod(line.substr(start, end - start)));
        start = end;
        end = line.find(',', start);
    }
}
SearchMatrix::SearchMatrix(list<string> mat, string startCell, string endCell) {
    //split the mat to cells with cost.
    _size = mat.size();
    int n = 0;
    for (n = 0; n< mat.size(); n++){
        vector<Cell> rowList = splitLineToCells(mat.front(), n);
        if( _size != rowList.size()){
            cout<< "invalid matrix, not N * N";
            exit(1);
        }
        mat.pop_front();
        _mat.push_back(rowList);
    }
    //initCell = startCell -->> cell
    Cell start = _mat.at(startCell[0]).at(startCell[2]);
    _initState = new State<Cell>(start,start.getValue());
    //goalCell = endCell -->> cell
    Cell end = _mat.at(endCell[0]).at(endCell[2]);
    _goalState = new State<Cell>(end,end.getValue());

}
State<Cell> SearchMatrix::getInitialState() {
    return _initState;
}

bool SearchMatrix::isGoalState(State<Cell> state) {
    return _goalState == state;
}


list<State<Cell>> SearchMatrix::getAllPossibleStates(Vector<State<Cell>> s) {
    list<State<Cell>> retval;
    // if !end of row/col
    int row = s.getState.getRow();
    int col = s.getState.getCol();
    //row +1, col
    if (row +1 < n && _mat.at(row+1).at(col).getValue()>-1){
        Cell c = _mat.at(row +1).at(col);
        retval.push_back(new State(c,s.getCost() + c.getValue(),&s))
    }
    //row - 1, col
    if (row - 1 > 0 |&& _mat.at(row -1).at(col).getValue()>-1){
        Cell c = _mat.at(row  -1).at(col);
        retval.push_back(new State(c,s.getCost() + c.getValue(),&s))
    }
    // row, col + 1
    if (col + 1 < n |&& _mat.at(row).at(col + 1).getValue()>-1){
        Cell c = _mat.at(row).at(col + 1);
        retval.push_back(new State(c,s.getCost() + c.getValue(),&s))
    }
    // row, col - 1
    if (col - 1 > 0 |&& _mat.at(row).at(col - 1).getValue()>-1){
        Cell c = _mat.at(row).at(col - 1);
        retval.push_back(new State(c,s.getCost() + c.getValue(),&s))
    }

    return retval;
}


#endif //MILESTONE_2_SEARCHMATRIX_H
