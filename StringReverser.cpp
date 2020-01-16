//
// Created by ziv on 14/01/2020.
//

#include "StringReverser.h"

string StringReverser::solve(string problem) {
    string retval = "";
    string::reverse_iterator itor;
    //iterator the reverse string
    for( itor = problem.rbegin(); itor != problem.rend(); itor++) {
        retval += *itor;
    }
    return retval;
}