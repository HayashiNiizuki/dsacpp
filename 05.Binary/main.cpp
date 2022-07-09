#include "../00.Macro/common.h"
#include "../04.Stack/stack.h"
#include "../04.Stack/queue.h"
#include "BinTree.h"
#include <iostream>

struct printX {
    int times = 0;
    void operator()(const int &a) {
        std::cout << a << "\t";
        if (times++ % 10 == 9)
            std::cout << std::endl;
    }
};

int main(int argc, char *argv[]) {
    printX _printX;
    BinTree<int> testTree;
    for (int i = 0; i < 100; i++) { //随机生成100个int并插入
        int t = rand() % 1000;
        _printX(t);
        if (testTree.empty())
            testTree.insert(t);
        else {
            BinNodePosi<int> temptr = testTree.root();
            bool ju = true;
            while (ju) {
                if (t < temptr->data) {
                    if (temptr->lc)
                        temptr = temptr->lc;
                    else {
                        temptr->insertAsLC(t);
                        ju = false;
                    }
                } else {
                    if (temptr->rc)
                        temptr = temptr->rc;
                    else {
                        temptr->insertAsRC(t);
                        ju = false;
                    }
                }
            }
        }
    }
    std::cout << std::endl;
    testTree.root()->travIn(_printX);
    return 0;
}
