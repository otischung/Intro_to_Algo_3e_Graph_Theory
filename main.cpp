#include "floyd_warshall.h"

int main() {
    int num_vertex, num_edge;
    int source, target, weight;
    bool ret;

    std::cin >> num_vertex >> num_edge;
    FloydWarshall g(num_vertex);
    for (int i = 0; i < num_edge; ++i) {
        std::cin >> source >> target >> weight;
        g.addEdge(source, target, weight);
    }
    g.floyd_warshall();
    g.print_distance();
    g.print_predecessor();
    return 0;
}
