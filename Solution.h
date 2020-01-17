//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_SOLUTION_H
#define MILESTONE_2_SOLUTION_H
#include <list>
#include <string>

using namespace std;
class Solution {
private:
    string path;
    int nodeEvaluated;
public:
    string getPath();
    int getNodeEvaluated();
};
template  <typename T>
int Solution::getNodeEvaluated() {
    return nodeEvaluated;
}
template  <typename T>
string Solution::getPath() {}

#endif //MILESTONE_2_SOLUTION_H
