#pragma once
#include "graph.h"

typedef enum COLOR {
    WHITE,
    GRAY,
    BLACK
} Color;

typedef struct NODE {
    Color color;
    int distance;
    int predecessor;
} Node;

class BFS : public Graph {
   protected:
    std::vector<Node> NodeAttr;

   public:
    BFS(int vertex);
    virtual ~BFS();
    void bfs(int source);
};
