#pragma once

template <typename Tv, typename Te>
void Graph<Tv, Te>::dfs(int s) { // full graph
    reset();
    int clock = 0;
    int v = s;
    do
        if (UNDISCOVERED == status(v))
            DFS(v, clock);
    while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
void Graph<Tv, Te>::DFS(int v, int &clock) { // single connected domain
    dTime(v) = ++clock;
    status(v) = DISCOVERED; // initialization
                            //
    printf("%s\n", vertex(v));
    /**/
    for (int u = firstNbr(v); - 1 < u; u = nextNbr(v, u))
        switch (status(u)) {
        case UNDISCOVERED: // u尚未发现，意味着支撑树可在此拓展
            type(v, u) = TREE;
            parent(u) = v;
            DFS(u, clock);
            break;
        case DISCOVERED: // u已被发现但尚未访问完毕，应属被后代指向的祖先
            type(v, u) = BACKWARD;
            break;
        default: // u已访问完毕（VISITED，有向图），则视承袭关系分为前向边或跨边
            type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
            break;
        }
    status(v) = VISITED;
    fTime(v) = ++clock; //至此，当前顶点v方告访问完毕
}