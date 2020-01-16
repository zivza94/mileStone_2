//
// Created by ziv on 16/01/2020.
//

#ifndef MILESTONE_2_SOLUTION_H
#define MILESTONE_2_SOLUTION_H
#include <list>
#include <string>

using namespace std;
template <typename T>
class Solution {
private:
    string path;
    int nodeEvaluated;
public:
    list<T> getPath();
    int getNodeEvaluated();
};
template  <typename T>
int Solution<T>::getNodeEvaluated() {
    return nodeEvaluated;
}
template  <typename T>
list<T> Solution<T>::getPath() {}


#endif //MILESTONE_2_SOLUTION_H
