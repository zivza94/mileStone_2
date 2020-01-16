//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_CELL_H
#define MILESTONE_2_CELL_H


class Cell {
private:
    int _row;
    int _col;
public:
    Cell(int row, int col): _row(row), _col(col){};
    int getRow(){ return  _row;}
    int getCol(){ return _col;}
};


#endif //MILESTONE_2_CELL_H
