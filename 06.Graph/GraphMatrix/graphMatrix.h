#pragma once

#include "../../02.Vector/vector.h"
#include "../Graph/graph.h"

template <typename Tv> struct Vertex { // Vertex
    Tv data;
    int inDegree, outDegree;
    VStatus status;
    int dTime, fTime;
    int parent;
    int priority;
    Vertex(Tv const &d = (Tv)0) // constructor
        : data(d), inDegree(0), outDegree(0), status(UNDISCOVERED), dTime(-1),
          fTime(-1), parent(-1), priority(__INT_MAX__) {}
};

template <typename Te> struct Edge { // Edge
    Te data;
    int weight;
    EType type;
    Edge(Te const &d, int w) // constructor
        : data(d), weight(w), type(UNDETERMINED) {}
};

template <typename Tv, typename Te> class GraphMatrix : public Graph<Tv, Te> {
  private:
    Vector<Vertex<Tv>> V;         // Vertex set (as Vector)
    Vector<Vector<Edge<Te> *>> E; // Edge set (as Matrix)
  public:
    int n, e;
    GraphMatrix() { n = e = 0; } // constructor
    ~GraphMatrix() {             // destructor
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                delete E[j][k];
    }
    /* basic operation of Vertex : inquire Vertex(i)'s */
    virtual Tv &vertex(int i) { return V[i].data; }         // data
    virtual int inDegree(int i) { return V[i].inDegree; }   // indegree
    virtual int outDegree(int i) { return V[i].outDegree; } // outdegree
    virtual int firstNbr(int i) { return nextNbr(i, n); }   // first Neighbour
    // next Neighbour after J
    virtual int nextNbr(int i, int j) {
        while ((-1 < j) && (!exists(i, --j)))
            ;
        return j;
    }
    virtual VStatus &status(int i) { return V[i].status; } // status
    virtual int &dTime(int i) { return V[i].dTime; }       // dTime
    virtual int &fTime(int i) { return V[i].fTime; }       // fTime
    virtual int &parent(int i) { return V[i].parent; }     // parent
    virtual int &priority(int i) { return V[i].priority; } // priority in ??

    /* dynamic operation of Vertex */
    virtual int insert(Tv const &vertex) { // insert a Vertex, return rank
        for (int j = 0; j < n; j++)
            E[j].insert((Edge<Te> *)nullptr);
        n++;
        E.insert(Vector<Edge<Te> *>(n, n, (Edge<Te> *)nullptr));
        return V.insert(Vertex<Tv>(vertex));
    }
    virtual Tv remove(int i) {      // delete a Vertex and all edge
        for (int j = 0; j < n; j++) // all out edge
            if (exists(i, j)) {
                delete E[i][j];
                V[j].inDegree--;
                e--;
            }
        E.remove(i);
        n--;
        Tv vBak = vertex(i);        // reserve this Vertex
        V.remove(i);                // remove Vertex
        for (int j = 0; j < n; j++) // all in edge
            if (Edge<Te> *x = E[j].remove(i)) {
                delete x;
                V[j].outDegree--;
                e--;
            }
        return vBak; // return Vertex
    }
    // is edge(u, v) exist ?
    virtual bool exists(int i, int j) {
        return (0 <= i) && (i < n) && (0 <= j) && (j < n) && E[i][j] != nullptr;
    }
    /* basic operation of Edge : inquire Edge(u, v)'s */
    virtual EType &type(int i, int j) { return E[i][j]->type; } // type
    virtual Te &edge(int i, int j) { return E[i][j]->data; }    // data
    virtual int &weight(int i, int j) {                         // weight
        return E[i][j]->weight;
    }
    /* dynamic operation of Edge */
    // insert Edge(u, v) weigh w
    virtual void insert(Te const &d, int w, int i, int j) {
        if (exists(i, j))
            return;
        E[i][j] = new Edge<Te>(d, w);
        e++;
        V[i].outDegree++;
        V[j].inDegree++;
    }
    // delete Edge(u, v)
    virtual Te remove(int i, int j) {
        Te eBak = edge(i, j); // reserve data
        delete E[i][j];
        E[i][j] = nullptr;
        e--;
        V[i].outDegree--;
        V[j].inDegree--;
        return eBak; // return data
    }
};