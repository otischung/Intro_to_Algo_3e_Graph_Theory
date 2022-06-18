#include "bellman_ford.h"

BellmanFord::BellmanFord(int vertex) : Graph(vertex) {
    table.resize(vertex, std::vector<int>(vertex, INT_MAX));
    predecessor.resize(vertex, -1);
}

bool BellmanFord::bellman_ford(int source) {
    int i, j;
    int u, v, w;

    table[0][source] = 0;
    table[1][source] = 0;
    for (i = 0; i < (int)AdjList[source].size(); ++i) {
        u = AdjList[source][i].target;
        w = AdjList[source][i].weight;
        table[1][u] = w;
    }
    for (i = 2; i < (int)table.size(); ++i) {
        for (j = 0; j < (int)table[i].size(); ++j) {  // Copy last state.
            table[i][j] = table[i - 1][j];
        }
        for (j = 0; j < (int)edge.size(); ++j) {
            u = edge[j].source;
            v = edge[j].target;
            w = edge[j].weight;
            if (table[i][u] != INT_MAX) {
                if (table[i][v] > table[i][u] + w) {
                    table[i][v] = table[i][u] + w;
                    predecessor[v] = u;
                }
            }
            // --- For Debuging ---
            // std::cout << "------------------\n";
            // std::cout << "edge " << j << ": " << u << '/' << v << '/' << w << '\n';
            // print_table();
            // std::cout << "------------------\n";
            // --- For Debuging ---
        }
    }
    i = (int)AdjList.size() - 1;
    for (j = 0; j < (int)edge.size(); ++j) {
        u = edge[j].source;
        v = edge[j].target;
        w = edge[j].weight;
        if (table[i][u] != INT_MAX && table[i][v] > table[i][u] + w) {
            return false;
        }
    }
    return true;
}

void BellmanFord::print_table() {
    for (int i = 0; i < (int)table.size(); ++i) {
        for (int j = 0; j < (int)table[i].size(); ++j) {
            if (table[i][j] == INT_MAX) {
                std::cout << "-\t";
            } else {
                std::cout << table[i][j] << '\t';
            }
        }
        std::cout << '\n';
    }
}
