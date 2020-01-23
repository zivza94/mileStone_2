//
// Created by liza on 21/01/2020.
//

#include "SolverQA.h"
#include "SearchMatrix.h"
#include "BFS.h"
#include "DFS.h"
#include "Cell.h"
#include "AStar.h"
string SolverQA::solve(string problem) {
    // build the matrix
    //Searcher<Cell*>* searcher = new BFS<Cell*>();
    Searcher<Cell*>* searcher = new AStar<Cell*>();
    Searchable<Cell*>* matrix = new SearchMatrix(problem);
    string answer = searcher->search(matrix);
    cout<<searcher->getEvaluated()<<endl;
    return answer.substr(0,answer.length() - 1);
}