//
// Created by liza on 21/01/2020.
//

#include "SolverQA.h"
#include "SearchMatrix.h"
#include "BFS.h"
#include "Cell.h"
string SolverQA::solve(string problem) {
    // build the matrix
    Searcher<Cell*>* searcher = new BFS<Cell*>();
    Searchable<Cell*>* matrix = new SearchMatrix(problem);
    return searcher->search(matrix);
 /*   Searchable<Cell*>*
    Searcher<Cell*>*searcher = new BFS<Cell*>();
    return searcher->search(<Searchable<Cell> *>(searchMatrix));*/
}