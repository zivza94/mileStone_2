//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_CELL_H
#define MILESTONE_2_CELL_H
#include <string>

using namespace std;
class Cell {
private:
    int _row;
    int _col;
    //-1 for infinty
    double _value;
public:
    Cell(int row, int col,double value): _row(row), _col(col), _value(value){};
    int getRow(){ return  _row;}
    int getCol(){ return _col;}
    double getValue(){return _value;}
};


#endif //MILESTONE_2_CELL_H
