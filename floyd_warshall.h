#pragma once
#include "graph.h"

class FloydWarshall : public Graph {
    protected:
    std::vector<std::vector<std::vector<int>>> distance;
    std::vector<std::vector<std::vector<int>>> predecessor;

    public:
    FloydWarshall(int vertex);
    void floyd_warshall();
    void print_distance();
    void print_predecessor();
};
