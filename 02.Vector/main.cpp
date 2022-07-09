#include "../00.Macro/common.h"
#include "vector.h"
#include <ctime>
#include <iostream>

struct _vectorPrint { // a function object for print
    int i = 0;        // record number of objects printed
    template <typename T> void operator()(T &a) {
        std::cout << a << "\t";
        if (i++ % 10 == 9)
            std::cout << std::endl; // endl every 10 number
    }
};

int main(int argc, char *argv[]) {
    _vectorPrint vectorPrint;
    int a[100];
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++) {
        a[i] = rand() % 1000;
    }
    Vector<int> testVector(a, 100);
    testVector.traverse(vectorPrint);
    std::cout << std::endl;
    testVector.sort(); // sort
    testVector.traverse(vectorPrint);
    return 0;
}
