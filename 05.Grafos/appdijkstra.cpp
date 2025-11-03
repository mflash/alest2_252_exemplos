#include <iostream>
#include "edgeweighteddigraph.h"
#include "dijkstrasp.h"

using namespace std;

int main()
{
  EdgeWeightedDigraph g("exemplos/tinyEWD.txt");
  DijkstraSP dij(g, "0");

  for (auto const &v : g.getVerts())
  {
    cout << v << ": ";
    if (dij.hasPathTo(v))
    {
      for (auto const &w : dij.pathTo(v))
        cout << w << " ";
      cout << "(" << dij.distTo(v) << ") ";
    }
    else
      cout << "SEM CAMINHO";
    cout << endl;
  }
}
