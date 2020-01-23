//
// Created by ziv on 20/01/2020.
//
#include "SearchMatrix.h"

int SearchMatrix::getHeuristicSearch(State<Cell *> *state) {
    int retval;
    int dx = _goalState->getState()->getRow() - state->getState()->getRow();
    int dy = _goalState->getState()->getCol() - state->getState()->getCol();
    retval = dx + dy;
    return retval;
}
State<Cell*>* SearchMatrix::getState(State<Cell*>* state,Cell* cell) {
    if (state == NULL){
        state = new State<Cell*>(cell,0);
    }
    return state;
}
vector<pair<Cell*,State<Cell*>*>> SearchMatrix::splitLineToCells(string line, int row) {
    vector<pair<Cell*,State<Cell*>*>> retval;
    int start = 0;
    int end = 0;
    int col = 0;
    if(line[line.size() - 1] != ','){
        line += ",";
    }
    end = line.find(',', start);
    while(end != -1) {

        Cell* c = new Cell(row, col,stod(line.substr(start, end - start)));
        retval.push_back(pair<Cell*,State<Cell*>*>(c,NULL));
        retval.back().second->setHeuristic(getHeuristicSearch(retval.back().second));
        start = end + 1;
        end = line.find(',', start);
        col++;
    }
    return retval;
}
SearchMatrix::SearchMatrix(string problem) {
    // split the problem to ,mat, start and end
    list<string> mat = splitProblemToMatrix(problem);
    string endCell = mat.back();
    mat.pop_back();
    string startCell = mat.back();
    mat.pop_back();


    string row;
    string col;
    //goalCell = endCell -->> cell
    //split the string to 2 ints
    row = endCell.substr(0,endCell.find(','));
    int endRow = stoi(row);
    col = endCell.substr(endCell.find(',') + 1);
    int endCol = stoi(col);
    Cell* end = _mat.at(endRow).at(endCol).first;
    _goalState = new State<Cell*>(end,end->getValue());
    _goalState->setHeuristic(0);
    _mat.at(endRow).at(endCol).second = _goalState;
    //initCell = startCell -->> cell
    //split the string to 2 ints
    row = startCell.substr(0,startCell.find(','));
    int startRow = stoi(row);
    col = startCell.substr(startCell.find(',') + 1);
    int startCol = stoi(col);
    Cell* start = _mat.at(startRow).at(startCol).first;
    _initState = new State<Cell*>(start,start->getValue());
    _initState->setHeuristic(getHeuristicSearch(_initState));
    _mat.at(startRow).at(startCol).second = _initState;

    //split the mat to cells with cost.
    _size = mat.size();
    int n = 0;
    for (n = 0; n< _size; n++){
        vector<pair<Cell*,State<Cell*>*>> rowList = splitLineToCells(mat.front(), n);
        if( _size != rowList.size()){
            cout<< "invalid matrix, not N * N";
            exit(1);
        }
        mat.pop_front();
        _mat.push_back(rowList);
    }






}
State<Cell*>* SearchMatrix::getInitialState() {
    return _initState;
}

bool SearchMatrix::isGoalState(State<Cell*>* state) {
    return *_goalState == *state;
}


list<State<Cell*>*> SearchMatrix::getAllPossibleStates(State<Cell*>* s) {
    list<State<Cell*>*> retval;
    // if !end of row/col
    int row = s->getState()->getRow();
    int col = s->getState()->getCol();
    State<Cell>* possibleState;
    //row +1, col
    if (row +1 < _size && col < _size && col >=0 && _mat.at(row+1).at(col).first->getValue()>-1){
        Cell* c = _mat.at(row +1).at(col).first;
        State<Cell*>* state = getState(_mat.at(row +1).at(col).second, c);
        _mat.at(row+1).at(col).second = state;
        retval.push_back(state);
    }
    //row - 1, col
    if (row - 1 >= 0 && col < _size && col >=0 &&_mat.at(row -1).at(col).first->getValue()>-1){
        Cell* c = _mat.at(row  -1).at(col).first;
        State<Cell*>* state = getState(_mat.at(row -1).at(col).second, c);
        _mat.at(row-1).at(col).second = state;
        retval.push_back(state);
        //retval.push_back(new State<Cell*>(c,s->getCost() + c->getValue()));
    }
    // row, col + 1
    if (col + 1 < _size && row < _size && row >= 0 && _mat.at(row).at(col + 1).first->getValue()>-1){
        Cell* c = _mat.at(row).at(col + 1).first;
        State<Cell*>* state = getState(_mat.at(row).at(col+1).second, c);
        _mat.at(row).at(col+1).second = state;
        retval.push_back(state);
        //retval.push_back(new State<Cell*>(c,s->getCost() + c->getValue()));
    }
    // row, col - 1
    if (col - 1 >= 0 && row < _size && row >= 0 &&_mat.at(row).at(col - 1).first->getValue()>-1){
        Cell* c = _mat.at(row).at(col - 1).first;
        State<Cell*>* state = getState(_mat.at(row).at(col-1).second, c);
        _mat.at(row).at(col-1).second = state;
        retval.push_back(state);
        //retval.push_back(new State<Cell*>(c,s->getCost() + c->getValue()));
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
    //retval.push_back(problem.substr(i));
    return retval;
}

SearchMatrix::~SearchMatrix() {
}