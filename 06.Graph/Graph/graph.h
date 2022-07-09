#pragma once

#include "../../04.Stack/stack.h"

// Status of Vertex
typedef enum { UNDISCOVERED, DISCOVERED, VISITED } VStatus;
//
typedef enum { UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD } EType;

template <typename Tv, typename Te> class Graph { // TypeVertex, TypeEdge
  private:
    void reset() {                    // reset status of all
        for (int i = 0; i < n; i++) { // all Vertex
            status(i) = UNDISCOVERED;
            dTime(i) = fTime(i) = -1;
            parent(i) = -1;
            priority(i) = __INT_MAX__;
            for (int j = 0; j < n; j++) // all Edge
                if (exists(i, j))
                    type(i, j) = UNDETERMINED;
        }
    }
    void BFS(int, int &);                     // Breadth-First Search
    void DFS(int, int &);                     // Depth-First Search
    void BCC(int, int &, Stack<int> &);       //
    bool TSort(int, int &, Stack<Tv> *);      //
    template <typename PU> void PFS(int, PU); //
  public:
    /* Vertex */
    int n;                              // num of Vertexs
    virtual int insert(Tv const &) = 0; // insert a Vertex, return rank
    virtual Tv remove(int) = 0;         // remove a Vertex and return it
    virtual Tv &vertex(int) = 0;        // data of a Vertex(if exist)
    virtual int inDegree(int) = 0;      // inDegree of a Vertex(if exist)
    virtual int outDegree(int) = 0;     // outDegree of a Vertex(if exist)
    virtual int firstNbr(int) = 0;      // first Neighbour of a Vertex
    virtual int nextNbr(int, int) = 0;  // next Neighbour of a Vertex after J
    virtual VStatus &status(int) = 0;   // status of Vertex
    virtual int &dTime(int) = 0;        // discover time
    virtual int &fTime(int) = 0;        // finash time
    virtual int &parent(int) = 0;       // parent of a Vertex
    virtual int &priority(int) = 0;     // priority in ??
    /* Edge */
    int e;                             // num of Edges
    virtual bool exists(int, int) = 0; // edge(u, v) exist or not
    virtual void insert(Te const &, int, int, int) = 0; // insert edge(u, v)
    virtual Te remove(int, int) = 0;   // delete edge(u, v) and return it
    virtual EType &type(int, int) = 0; // type of Edge(v, u)
    virtual Te &edge(int, int) = 0;    // data of Edge(v, u) (if exist)
    virtual int &weight(int, int) = 0; // weight of Edge(v, u)
    /* algorithm */
    void bfs(int);                            //
    void dfs(int);                            //
    void bcc(int);                            //
    Stack<Tv> *tSort(int);                    //
    void prim(int);                           //
    void dijkstra(int);                       //
    template <typename PU> void pfs(int, PU); //
};

#include "graph_implementation.h"