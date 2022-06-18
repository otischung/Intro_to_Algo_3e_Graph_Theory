# Introduction to Algorithm 3e Graph Theory

## Inheritance Relationship

![Alt text](https://g.gravizo.com/svg?
  digraph G {
    "Graph" -> "BFS";
    "Graph" -> "DFS";
    "Graph" -> "DisjointSet";
    "Graph" -> "BellmanFord";
    "Graph" -> "FloydWarshall";
    "DFS" -> "TopologicalSort";
    "DisjointSet" -> "Kruskal";
  }
)
![Alt text](https://g.gravizo.com/svg?%20digraph%20G%20{%20%22Graph%22%20-%3E%20%22BFS%22;%20%22Graph%22%20-%3E%20%22DFS%22;%20%22Graph%22%20-%3E%20%22DisjointSet%22;%20%22Graph%22%20-%3E%20%22BellmanFord%22;%20%22Graph%22%20-%3E%20%22FloydWarshall%22;%20%22DFS%22%20-%3E%20%22TopologicalSort%22;%20%22DisjointSet%22%20-%3E%20%22Kruskal%22;%20})



## Usage

Let's say you want to implement Kruskal's algorithm. According to the inheritance graph shown above, we need `graph.h`, `disjoint_set.h` and `kruskal.h`.

### Header File

You only need to include the target header file in your `main.cpp`, which is `kruskal.h`

### Makefile

You only need to compile all the dependency `.cpp` file, which are `graph.cpp`, `disjoint_set.cpp`, `kruskal.cpp` and your `main.cpp`

