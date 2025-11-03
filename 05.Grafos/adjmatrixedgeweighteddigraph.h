#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "edge.h"
#include "edgeweighteddigraph.h"

class AdjMatrixEdgeWeightedDigraph {
private:
    int totalVertices;
    int totalEdges;
    int** adj;
    int* data;
    std::unordered_map<std::string, int> dic;
    std::unordered_map<int, std::string> dic2;
    EdgeWeightedDigraph g;

public:
    AdjMatrixEdgeWeightedDigraph(EdgeWeightedDigraph& graph);
    int mapToArray(const std::string& v) const;
    std::string mapToString(int v) const;
    int getTotalVertices() const;
    int getTotalEdges() const;
    void addEdge(const Edge& e);
    std::vector<Edge> getAdj(const std::string& v);
    std::string toString() const;
    ~AdjMatrixEdgeWeightedDigraph();
};

