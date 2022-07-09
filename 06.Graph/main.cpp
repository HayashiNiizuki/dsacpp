#include "stdio.h"
#include "../00.Macro/common.h"
#include "GraphMatrix/graphMatrix.h"

int main(int argc, char *argv[]) {
    GraphMatrix<char *, int> testGM;
    { // construct
        char Clr[] = "Clr", Wzh[] = "Wzh", Zjl[] = "Zjl", Zxc[] = "Zxc",
             Wxe[] = "Wxe", Lp[] = "Lp", Wcy[] = "Wcy", Sj[] = "Sj";
        testGM.insert(Clr); // 0
        testGM.insert(Wzh); // 1
        testGM.insert(Zjl); // 2
        testGM.insert(Zxc); // 3
        testGM.insert(Wxe); // 4
        testGM.insert(Lp);  // 5
        testGM.insert(Wcy); // 6
        testGM.insert(Sj);  // 7
        int time, weight;
        { // Clr
            testGM.insert(time = 12, weight = 1, 0, 1);
            testGM.insert(time = 8, weight = 1, 0, 2);
            testGM.insert(time = 24, weight = 1, 0, 3);
            testGM.insert(time = 24, weight = 1, 0, 4);
            testGM.insert(time = 8, weight = 1, 0, 5);
            testGM.insert(time = 2, weight = 1, 0, 7);
        }
        { // Wzh
            testGM.insert(time = 8, weight = 1, 1, 2);
            testGM.insert(time = 12, weight = 1, 3, 1);
            testGM.insert(time = 2, weight = 1, 4, 1);
            testGM.insert(time = 8, weight = 1, 1, 5);
            testGM.insert(time = 2, weight = 1, 1, 7);
        }
        { // Zjl
            testGM.insert(time = 8, weight = 1, 3, 2);
            testGM.insert(time = 8, weight = 1, 2, 5);
            testGM.insert(time = 1, weight = 1, 2, 7);
        }
        { // Zxc
            testGM.insert(time = 24, weight = 1, 4, 3);
            testGM.insert(time = 16, weight = 1, 3, 5);
            testGM.insert(time = 8, weight = 1, 3, 6);
            testGM.insert(time = 10, weight = 1, 3, 7);
        }
        { // Wxe
            testGM.insert(time = 6, weight = 1, 4, 5);
            testGM.insert(time = 6, weight = 1, 4, 6);
            testGM.insert(time = 6, weight = 1, 4, 7);
        }
        { // Lp
            testGM.insert(time = 7, weight = 1, 5, 6);
            testGM.insert(time = 10, weight = 1, 5, 7);
        }
        { // Wcy
            testGM.insert(time = 7, weight = 1, 7, 6);
        }
    }
    printf("n : %d;\te : %d\n", testGM.n, testGM.e);
    testGM.bfs(2);
    printf("Success!\n");
    return 0;
}
