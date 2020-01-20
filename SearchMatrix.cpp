//
// Created by ziv on 20/01/2020.
//
#include "SearchMatrix.h"

vector<Cell> SearchMatrix::splitLineToCells(string line, int row) {
    vector<Cell> retval;
    int start = 0;
    int end = 0;
    if(line[line.size() - 1] != ','){
        line += ",";
    }
    end = line.find(',', start);
    while(end != -1) {
        Cell* c = new Cell(row, end/2,stod(line.substr(start, end - start)));
        retval.push_back(*c);
        start = end + 1;
        end = line.find(',', start);
    }
}
SearchMatrix::SearchMatrix(string problem) {
    // split the problem to ,mat, start and end
    list<string> mat = splitProblemToMatrix(problem);
    string endCell = mat.back();
    mat.pop_back();
    string startCell = mat.back();
    mat.pop_back();


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
    string row;
    string col;
    //initCell = startCell -->> cell
    //split the string to 2 ints
    row = startCell.substr(0,startCell.find(','));
    int startRow = stoi(row);
    col = startCell.substr(startCell.find(','));
    int startCol = stoi(col);
    Cell start = _mat.at(startRow).at(startCol);
    _initState = new State<Cell>(start,start.getValue());
    //goalCell = endCell -->> cell
    //split the string to 2 ints
    row = endCell.substr(0,endCell.find(','));
    int endRow = stoi(row);
    col = endCell.substr(endCell.find(','));
    int endCol = stoi(col);
    Cell end = _mat.at(endRow).at(endCol);
    _goalState = new State<Cell>(end,end.getValue());



}
State<Cell>* SearchMatrix::getInitialState() {
    return _initState;
}

bool SearchMatrix::isGoalState(State<Cell> state) {
    return *_goalState == state;
}


list<State<Cell>*> SearchMatrix::getAllPossibleStates(State<Cell> s) {
list<State<Cell>*> retval;
// if !end of row/col
int row = s.getState().getRow();
int col = s.getState().getCol();
State<Cell>* possibleState;
//row +1, col
if (row +1 < _size && _mat.at(row+1).at(col).getValue()>-1){
Cell c = _mat.at(row +1).at(col);
retval.push_back(new State<Cell>(c,s.getCost() + c.getValue(),&s));
}
//row - 1, col
if (row - 1 > 0 && _mat.at(row -1).at(col).getValue()>-1){
Cell c = _mat.at(row  -1).at(col);
retval.push_back(new State<Cell>(c,s.getCost() + c.getValue(),&s));
}
// row, col + 1
if (col + 1 < _size && _mat.at(row).at(col + 1).getValue()>-1){
Cell c = _mat.at(row).at(col + 1);
retval.push_back(new State<Cell>(c,s.getCost() + c.getValue(),&s));
}
// row, col - 1
if (col - 1 > 0 && _mat.at(row).at(col - 1).getValue()>-1){
Cell c = _mat.at(row).at(col - 1);
retval.push_back(new State<Cell>(c,s.getCost() + c.getValue(),&s));
}

return retval;
}

list<string> SearchMatrix::splitProblemToMatrix(string problem) {
    list<string> retval;
    int i = 0;
    int j;
    for (j=0; j<problem.size(); j++){
        if (problem[j] == '\n'){
            retval.push_back(problem.substr(i,j-i));
            i =j + 1;
        }
    }
    retval.push_back(problem.substr(i));
    return retval;
}

SearchMatrix::~SearchMatrix() {
}