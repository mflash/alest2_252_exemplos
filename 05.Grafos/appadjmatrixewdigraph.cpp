#include <iostream>
#include "adjmatrixedgeweighteddigraph.h"

int main() {
    EdgeWeightedDigraph g("exemplos/tinyEWD.txt");
    AdjMatrixEdgeWeightedDigraph ag(g);
    std::cout << g.toDot() << std::endl;
    std::cout << ag.toString() << std::endl;
    return 0;
}
