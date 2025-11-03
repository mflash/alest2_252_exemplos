#include "dijkstrasp.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "indexminheap.h"

using namespace std;

DijkstraSP::DijkstraSP(EdgeWeightedDigraph &g, string s)
{
    this->s = s;
    bfs(g, s);
}

void DijkstraSP::bfs(EdgeWeightedDigraph &g, string v)
{
    for (auto const &v : g.getVerts())
        _distTo[v] = (float) 100000;
    _distTo[s] = 0.0;

    pq.put(s, 0.0);
    while (!pq.isEmpty()) {
        string v = pq.delMin();
        cout << "Processando " << v << endl;
        for (auto const &e : g.getAdj(v)) {
            cout << "  " << e << endl;
            relax(e);
        }
    }
}

void DijkstraSP::relax(const Edge& e) {
    string v = e.v;
    string w = e.w;
    float edgeWeight = _distTo[v] + e.weight;

    if (_distTo[w] > edgeWeight) {
        // Achei um caminho melhor!
        _distTo[w] = edgeWeight;
        edgeTo[w] = e;
        if (!pq.contains(w))
            // Não existe, insere na fila
            pq.put(w, edgeWeight);
        else
            // Já existe, reduz a prioridade (valor)
            pq.decreaseValue(w, edgeWeight);
    }
}

bool DijkstraSP::hasPathTo(string s)
{
    return edgeTo.find(s) != edgeTo.end();
}

float DijkstraSP::distTo(string s)
{
    if (hasPathTo(s))
        return _distTo[s];
    return -1;
}

vector<Edge> DijkstraSP::pathTo(string v)
{
    vector<Edge> path;
    if(!hasPathTo(v))
        return path;

    Edge& e = edgeTo[v];
    while (e.v != s)
    {
        path.insert(path.begin(), e);
        e = edgeTo[e.v];
    }
    path.insert(path.begin(), e);
    return path;
}

