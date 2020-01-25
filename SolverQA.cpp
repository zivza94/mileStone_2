//
// Created by liza on 21/01/2020.
//

#include "SolverQA.h"
#include "SearchMatrix.h"
#include "BFS.h"
#include "DFS.h"
#include "Cell.h"
#include "AStar.h"
#include "BestFS.h"
string SolverQA::solve(string problem) {
    // create the searcher
    Searcher<Cell*>* searcher = new AStar<Cell*>();
    // build the matrix
    Searchable<Cell*>* matrix = new SearchMatrix(problem);
    //solve
    string answer = searcher->search(matrix);
    return answer;
}