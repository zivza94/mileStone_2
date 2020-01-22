#include <iostream>
#include "Solver.h"
#include "StringReverser.h"
#include "Main.h"

using namespace std ;

int main(int argc, char *argv[]) {
    boot::Main* m = new boot::Main();
    if (argc > 1) {
        m->main(stoi(argv[1]));
    }
    // default port is 5600
    else {
        m->main(stoi("5600"));
    }
    return 0;
}
