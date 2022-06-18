#include "graph.h"

Graph::Graph(int vertex) {
    AdjList.resize(vertex);
    AdjMat.resize(vertex, std::vector<int>(vertex, INT_MAX));
    for (int i = 0; i < (int)AdjMat.size(); ++i) {
        AdjMat[i][i] = 0;
    }
}

Graph::~Graph() {}

void Graph::addEdge(int source, int target, int weight) {
    Edge e;
    e.source = source;
    e.target = target;
    e.weight = weight;
    edge.push_back(e);
    AdjList[source].push_back(e);
    AdjMat[source][target] = weight;
}

void Graph::printGraph() {
    std::cout << "----- Adjacency List -----\n";
    std::cout << "source: target/weight\n";
    for (int i = 0; i < (int)AdjList.size(); ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < (int)AdjList[i].size(); ++j) {
            std::cout << AdjList[i][j].target << '/' << AdjList[i][j].weight << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl;

    std::cout << "----- Adjacency Matrix -----\n";
    for (int i = 0; i < (int)AdjMat.size(); ++i) {
        std::cout << '\t' << i;
    }
    std::cout << '\n';
    for (int i = 0; i < (int)AdjMat.size(); ++i) {
        std::cout << i;
        for (int j = 0; j < (int)AdjMat[i].size(); ++j) {
            if (AdjMat[i][j] == INT_MAX) {
                std::cout << "\t-";
            } else {
                std::cout << '\t' << AdjMat[i][j];
            }
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
}
