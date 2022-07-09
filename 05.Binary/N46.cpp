#include "BinTree.h"
#include <cstdio>
#include <ctime>
#include <string>

// for test
#include "N46\member.h"
#include "N46\splitWithStl.h"

int main(int argc, char *argv[]) {
    //读取系统时间
    time_t t = time(&t);
    struct tm *local = localtime(&t);
    int d = local->tm_mday;
    int m = local->tm_mon + 1;
    int y = local->tm_year + 1900;
    //读入文件
    ifstream infile_1("./N46/N46Member-Graduated.in");
    ifstream infile_2("./N46/N46Member.in");
    if (!(infile_1.is_open() && infile_2.is_open()))
        cout << "Open failed!\n";
    else {
        string temp;
        BinTree<member> memTree;
        while (getline(infile_1, temp)) {
            member tempmem(temp);
            tempmem.ageupdate(d, m, y);
            
        }
    }
    return 0;
}