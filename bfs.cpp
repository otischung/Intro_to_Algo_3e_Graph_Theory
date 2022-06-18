#include "bfs.h"

BFS::BFS(int vertex) : Graph(vertex) {
    NodeAttr.resize(vertex);
}

BFS::~BFS() {}

void BFS::bfs(int source) {
    std::queue<int> q;
    int u, v;

    for (int i = 0; i < (int)NodeAttr.size(); ++i) {
        if (i == source) {
            continue;
        }
        NodeAttr[i].color = WHITE;
        NodeAttr[i].distance = INT_MAX;
        NodeAttr[i].predecessor = -1;
    }
    NodeAttr[source].color = GRAY;
    NodeAttr[source].distance = 0;
    NodeAttr[source].predecessor = -1;

    q.push(source);
    while ((int)q.size() > 0) {
        u = q.front();
        q.pop();
        std::cout << u << ' ';
        for (int i = 0; i < (int)AdjList[u].size(); ++i) {
            v = AdjList[u][i].target;
            if (NodeAttr[v].color == WHITE) {
                NodeAttr[v].color = GRAY;
                NodeAttr[v].distance = NodeAttr[u].distance + 1;
                NodeAttr[v].predecessor = u;
                q.push(v);
            }
        }
        NodeAttr[u].color = BLACK;
    }
    std::cout << std::endl;
}
