#pragma once
#include <bits/stdc++.h>

typedef struct EDGE {
    int source;  // Needs by Kruskal's algorithm
    int target;
    int weight;
} Edge;

class Graph {
   protected:
    std::vector<Edge> edge;
    std::vector<std::vector<Edge>> AdjList;
    std::vector<std::vector<int>> AdjMat;

   public:
    Graph(int vertex);
    virtual ~Graph();
    void addEdge(int source, int target, int weight);
    virtual void printGraph();
};
