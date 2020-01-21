//
// Created by liza on 21/01/2020.
//

#ifndef MILESTONE_2_SOLVERQA_H
#define MILESTONE_2_SOLVERQA_H


#include <string>
#include "Solver.h"
using namespace std;

// object adapter that implements Solver and has searchable method for helping him do that.
class SolverQA : public Solver<string, string> {
private:

public:
    string solve (string problem) override;
};


#endif //MILESTONE_2_SOLVERQA_H
