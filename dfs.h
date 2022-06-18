#pragma once
#include "graph.h"

typedef enum COLOR {
    WHITE,
    GRAY,
    BLACK
} Color;

typedef struct NODE {
    Color color;
    int discover;
    int finish;
    int predecessor;
} Node;

class DFS : public Graph {
   protected:
    std::vector<Node> NodeAttr;
    int time;

   public:
    DFS(int vertex);
    virtual ~DFS();
    void dfs(int source);
    virtual void dfs_visit(int u);
    virtual void printGraph();
};
