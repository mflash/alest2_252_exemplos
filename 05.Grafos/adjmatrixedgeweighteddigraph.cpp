#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <stdexcept>
#include "adjmatrixedgeweighteddigraph.h"

AdjMatrixEdgeWeightedDigraph::AdjMatrixEdgeWeightedDigraph(EdgeWeightedDigraph& graph) {

    g = graph;
    totalVertices = 0;
    for (const auto& v : g.getVerts()) {
        dic[v] = totalVertices;
        dic2[totalVertices] = v;
        totalVertices++;
    }

    adj = (int**) malloc(totalVertices * sizeof(int*));
    data = (int*) malloc(totalVertices * totalVertices * sizeof(int));

    for(int i=0; i<totalVertices; i++) {
      adj[i] = &data[i*totalVertices];
    }

    for(int i=0; i<totalVertices; i++)
      for(int j=0; j<totalVertices; j++)
        adj[i][j] = -1; // Initialize all weights to -1 (no edge)

    for (const auto& e : g.getEdges()) {
        addEdge(e);
    }
}

int AdjMatrixEdgeWeightedDigraph::mapToArray(const std::string& v) const {
    return dic.at(v);
}

std::string AdjMatrixEdgeWeightedDigraph::mapToString(int v) const {
    return dic2.at(v);
}

int AdjMatrixEdgeWeightedDigraph::getTotalVertices() const {
    return totalVertices;
}

int AdjMatrixEdgeWeightedDigraph::getTotalEdges() const {
    return totalEdges;
}

void AdjMatrixEdgeWeightedDigraph::addEdge(const Edge& e) {
    std::string v = e.v;
    std::string w = e.w;
    int v1 = dic[v];
    int w1 = dic[w];
    if (adj[v1][w1] == -1) {
        adj[v1][w1] = e.weight;
        totalEdges++;
    }
}

std::vector<Edge> AdjMatrixEdgeWeightedDigraph::getAdj(const std::string& v) {
    return g.getAdj(v);
}

std::string AdjMatrixEdgeWeightedDigraph::toString() const {
    std::ostringstream oss;
    oss << "  ";
    for (int i = 0; i < totalVertices; ++i) {
        oss << std::setw(6) << i;
    }
    oss << "\n";
    for (int i = 0; i < totalVertices; ++i) {
        oss << i << " ";
        for (int j = 0; j < totalVertices; ++j) {
            if (adj[i][j] != -1) {
                oss << std::setw(5) << std::fixed << std::setprecision(2) << adj[i][j] << " ";
            } else {
                oss << "----- ";
            }
        }
        oss << "\n";
    }
    return oss.str();
}

AdjMatrixEdgeWeightedDigraph::~AdjMatrixEdgeWeightedDigraph() {
    free(data);
    free(adj);
}

