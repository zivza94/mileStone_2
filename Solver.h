//
// Created by ziv on 14/01/2020.
//

#ifndef MILESTONE_2_SOLVER_H
#define MILESTONE_2_SOLVER_H
template <class P, class S>
class Solver {
public:
    virtual S solve(P problem) = 0;
    virtual ~Solver(){};
};
#endif //MILESTONE_2_SOLVER_H
