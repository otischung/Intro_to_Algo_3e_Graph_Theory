#include "kruskal.h"

bool Kruskal::cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

Kruskal::Kruskal(int vertex) : DisjointSet(vertex) {}

void Kruskal::sortEdge() {
    std::sort(edge.begin(), edge.end(), cmp);
}

void Kruskal::kruskal() {
    sortEdge();
    for (int i = 0; i < (int)edge.size(); ++i) {
        if (find_set(edge[i].source) != find_set(edge[i].target)) {
            edge_chosen.push_back(edge[i]);
            union_set(edge[i].source, edge[i].target);
        }
    }

    std::cout << "The edges which are chosen is shown below.\n";
    std::cout << "source/target/weight\n";
    for (int i = 0; i < (int)edge_chosen.size(); ++i) {
        std::cout << edge_chosen[i].source << '/' << edge_chosen[i].target << '/' << edge_chosen[i].weight << '\n';
    }
}
