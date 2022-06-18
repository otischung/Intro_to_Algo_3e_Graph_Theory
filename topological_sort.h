#pragma once
#include "dfs.h"

class TopologicalSort : public DFS {
   protected:
    std::list<int> result;

   public:
    TopologicalSort(int vertex);
    virtual ~TopologicalSort();
    virtual void dfs_visit(int u);
    void sort();
};
