#include "disjoint_set.h"

DisjointSet::DisjointSet(int vertex) : Graph(vertex) {
    Node n;
    n.predecessor = -1;
    n.rank = 1;
    NodeAttr.resize(vertex, n);
}

DisjointSet::~DisjointSet() {}

int DisjointSet::find_set(int u) {
    int root = u;
    while (NodeAttr[root].predecessor != -1) {
        root = NodeAttr[root].predecessor;
    }
    return root;
}
bool DisjointSet::union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v) {
        return false;
    }
    if (NodeAttr[u].rank >= NodeAttr[v].rank) {
        NodeAttr[u].rank += NodeAttr[v].rank;
        NodeAttr[v].rank = 0;
        NodeAttr[v].predecessor = u;
    } else {
        NodeAttr[v].rank += NodeAttr[u].rank;
        NodeAttr[u].rank = 0;
        NodeAttr[u].predecessor = v;
    }
    return true;
}
