#include "queue.h"
#include <iostream>

int main() {
    Queue<int> qu;
    qu.enqueue(1024);
    std::cout << qu.dequeue() << std::endl;
    return 0;
}