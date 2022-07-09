#include "list.h"
#include <ctime>
#include <iostream>

void listPrint(List<int> e) {
    ListNodePosi<int> x = e.first();
    for (int i = 0; i < e.size(); i++) {
        std::cout << x->data << "\t";
        x = x->succ;
        if (i % 10 == 9)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    List<int> test;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 100; i++)
        test.insertAsLast(rand() % 1000000);
    //test.uniquify();
    listPrint(test);
    test.sort();
    listPrint(test);
    return 0;
}
