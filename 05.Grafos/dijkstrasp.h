#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <map>
#include <set>
#include <string>
#include "edgeweighteddigraph.h"
#include "indexminheap.h"

class DijkstraSP
{

public:
	DijkstraSP(EdgeWeightedDigraph &g, std::string s);

	bool hasPathTo(std::string v);
	std::vector<Edge> pathTo(std::string v);
	float distTo(std::string v);

private:
  std::string s;
	std::map<std::string, Edge> edgeTo;
	std::map<std::string, int> _distTo;
  IndexMinHeap<std::string, float> pq;
	void bfs(EdgeWeightedDigraph &g, std::string v);

  void relax(const Edge& e);
};

#endif
