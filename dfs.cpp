#include "dfs.h"

DFS::DFS(int vertex) : Graph(vertex), time(0) {
    NodeAttr.resize(vertex);
}

DFS::~DFS() {}

void DFS::dfs(int source) {
    int u;
    bool first = true;

    for (int i = 0; i < (int)NodeAttr.size(); ++i) {
        NodeAttr[i].color = WHITE;
        NodeAttr[i].discover = INT_MAX;
        NodeAttr[i].finish = INT_MAX;
        NodeAttr[i].predecessor = -1;
    }
    time = 0;
    for (int i = 0; i < (int)NodeAttr.size(); ++i) {
        if (first) {
            first = false;
            u = source;
        } else {
            u = i;
        }
        if (NodeAttr[u].color == WHITE) {
            dfs_visit(u);
        }
    }
}

void DFS::dfs_visit(int u) {
    int v;
    NodeAttr[u].discover = ++time;
    NodeAttr[u].color = GRAY;
    for (int i = 0; i < (int)AdjList[u].size(); ++i) {
        v = AdjList[u][i].target;
        if (NodeAttr[v].color == WHITE) {
            NodeAttr[i].predecessor = u;
            dfs_visit(v);
        }
    }
    NodeAttr[u].color = BLACK;
    NodeAttr[u].finish = ++time;
}

void DFS::printGraph() {
    Graph::printGraph();
    std::cout << '\n';
    std::cout << "----- DFS vertex information -----\n";
    std::cout << "vertex: discover/finish\n";
    for (int i = 0; i < (int)NodeAttr.size(); ++i) {
        std::cout << i << ": " << NodeAttr[i].discover << '/' << NodeAttr[i].finish << '\n';
    }
    std::cout << std::endl;
}
