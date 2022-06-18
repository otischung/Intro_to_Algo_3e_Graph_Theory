#include "topological_sort.h"

TopologicalSort::TopologicalSort(int vertex): DFS(vertex) {}

TopologicalSort::~TopologicalSort() {}

void TopologicalSort::dfs_visit(int u) {
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
    result.push_front(u);
}

void TopologicalSort::sort() {
    dfs(0);
    for (auto it = result.begin(); it != result.end(); ++it) {  // std::list<int>::iterator it
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}
