#pragma once
#include "disjoint_set.h"

class Kruskal : public DisjointSet {
   protected:
    std::vector<Edge> edge_chosen;

    static bool cmp(Edge a, Edge b);

   public:
    Kruskal(int vertex);
    void sortEdge();
    void kruskal();
};
