#pragma once
#include "graph.h"

class BellmanFord : public Graph {
   protected:
    std::vector<std::vector<int>> table;
    std::vector<int> predecessor;

   public:
    BellmanFord(int vertex);
    bool bellman_ford(int source);
    void print_table();
};
