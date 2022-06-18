#include "floyd_warshall.h"

FloydWarshall::FloydWarshall(int vertex) : Graph(vertex) {
    distance.resize(vertex + 1, std::vector<std::vector<int>>(vertex, std::vector<int>(vertex, INT_MAX)));
    predecessor.resize(vertex + 1, std::vector<std::vector<int>>(vertex, std::vector<int>(vertex, -1)));
}

void FloydWarshall::floyd_warshall() {
    distance[0] = AdjMat;
    for (int i = 0; i < (int)distance[0].size(); ++i) {
        for (int j = 0; j < (int)distance[0][i].size(); ++j) {
            if (distance[0][i][j] != 0 && distance[0][i][j] != INT_MAX) {
                predecessor[0][i][j] = i;
            }
        }
    }
    
    for (int i = 1; i < (int)distance.size(); ++i) {
        for (int j = 0; j < (int)distance[i].size(); ++j) {
            for (int k = 0; k < (int)distance[i][j].size(); ++k) {
                if (distance[i - 1][j][i - 1] == INT_MAX || distance[i - 1][i - 1][k] == INT_MAX) {
                    distance[i][j][k] = distance[i - 1][j][k];
                    predecessor[i][j][k] = predecessor[i - 1][j][k];
                } else {
                    if (distance[i - 1][j][k] > distance[i - 1][j][i - 1] + distance[i - 1][i - 1][k]) {
                        distance[i][j][k] = distance[i - 1][j][i - 1] + distance[i - 1][i - 1][k];
                        predecessor[i][j][k] = predecessor[i - 1][i - 1][k];
                    } else {
                        distance[i][j][k] = distance[i - 1][j][k];
                        predecessor[i][j][k] = predecessor[i - 1][j][k];
                    }
                }
            }
        }
    }
}

void FloydWarshall::print_distance() {
    std::cout << "----- Begin distance matrix -----\n";
    for (int i = 0; i < (int)distance.size(); ++i) {
        std::cout << "Iteration " << i << ":\n";
        std::cout << "--------------------\n";
        for (int j = 0; j < (int)distance[i].size(); ++j) {
            for (int k = 0; k < (int)distance[i][j].size(); ++k) {
                if (distance[i][j][k] == INT_MAX) {
                    std::cout << "-\t";
                } else {
                    std::cout << distance[i][j][k] << '\t';
                }
            }
            std::cout << '\n';   
        }
    }
    std::cout << "----- End distance matrix -----\n\n";
}

void FloydWarshall::print_predecessor() {
    std::cout << "----- Begin predecessor matrix -----\n";
    for (int i = 0; i < (int)predecessor.size(); ++i) {
        std::cout << "Iteration " << i << ":\n";
        std::cout << "--------------------\n";
        for (int j = 0; j < (int)predecessor[i].size(); ++j) {
            for (int k = 0; k < (int)predecessor[i][j].size(); ++k) {
                if (predecessor[i][j][k] == -1) {
                    std::cout << "-\t";
                } else {
                    std::cout << predecessor[i][j][k] << '\t';
                }
            }
            std::cout << '\n';   
        }
    }
    std::cout << "----- End predecessor matrix -----\n\n";
}
