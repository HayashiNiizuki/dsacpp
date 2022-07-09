#pragma once

#include "../../04.Stack/queue.h"

template <typename Tv, typename Te> void Graph<Tv, Te>::bfs(int s) {
    reset();
    int clock = 0;
    int v = s;
    do {
        if (status(v) == UNDISCOVERED)
            BFS(v, clock);
    } while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::BFS(int v, int &clock) { // single connected domain
    Queue<int> Q;
    status(v) = DISCOVERED;
    Q.enqueue(v); // initialization
    while (!Q.empty()) {
        int v = Q.dequeue();
        dTime(v) = ++clock;
        /**/
        printf("%s\n", vertex(v));
        /**/
        for (int u = firstNbr(v); u > -1; u = nextNbr(v, u)) {
            if (status(u) == UNDISCOVERED) {
                status(u) = DISCOVERED;
                Q.enqueue(u);
                parent(u) = v;
                type(v, u) = TREE; // BFS Tree
            } else
                type(v, u) = CROSS;
        }
        status(v) = VISITED;
    }
}