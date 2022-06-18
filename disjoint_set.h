#pragma once
#include "graph.h"

typedef struct NODE {
    int rank;
    int predecessor;
} Node;

class DisjointSet : public Graph {
   protected:
    std::vector<Node> NodeAttr;

   public:
    DisjointSet(int vertex);
    virtual ~DisjointSet();
    int find_set(int u);
    bool union_set(int u, int v);
};
