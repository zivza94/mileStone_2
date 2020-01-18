#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "Main.h"

using namespace std ;

int main(int argc, char *argv[]) {
    boot::Main* m = new boot::Main();
    m->main(stoi(argv[1])) ;
    return 0;
}
