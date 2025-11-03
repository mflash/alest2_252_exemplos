CPPFLAGS = -Wall -g -std=c++17   # Opções do compilador: todos warnings e debug info

all: appgraph appdigraph appdfs appbfs appciclonaodirigido appciclodirigido apptopo appufind appewgraph appkruskal appindexminheap appdijkstra appadjmatrixewdigraph

# classe Graph
appgraph = appgraph
appgraph_src = appgraph.cpp graph.cpp
appgraph_obj = $(appgraph_src:.cpp=.o)

# classe Digraph
appdgraph = appdigraph
appdgraph_src = appdigraph.cpp digraph.cpp graph.cpp
appdgraph_obj = $(appdgraph_src:.cpp=.o)

# DFS
appdfs = appdfs
appdfs_src = appdfs.cpp graph.cpp dfs.cpp
appdfs_obj = $(appdfs_src:.cpp=.o)

# BFS
appbfs = appbfs
appbfs_src = appbfs.cpp graph.cpp bfs.cpp
appbfs_obj = $(appbfs_src:.cpp=.o)

# Ciclos nao dirigidos
appciclonaodirigido = appciclonaodirigido
appciclonaodirigido_src = appciclonaodirigido.cpp ciclonaodirigido.cpp graph.cpp
appciclonaodirigido_obj = $(appciclonaodirigido_src:.cpp=.o)

# Ciclos dirigidos
appciclodirigido = appciclodirigido
appciclodirigido_src = appciclodirigido.cpp ciclodirigido.cpp digraph.cpp graph.cpp
appciclodirigido_obj = $(appciclodirigido_src:.cpp=.o)

# Ordem topologica
apptopo = apptopo
apptopo_src = apptopo.cpp ordtopologica.cpp digraph.cpp graph.cpp
apptopo_obj = $(apptopo_src:.cpp=.o)

# classe UnionFind
appufind = appufind
appufind_src = appunionfind.cpp unionfind.cpp edgeweightedgraph.cpp
appufind_obj = $(appufind_src:.cpp=.o)

# classe EdgeWeightedGraph
appewgraph = appewgraph
appewgraph_src = appewgraph.cpp edgeweightedgraph.cpp
appewgraph_obj = $(appewgraph_src:.cpp=.o)

# classe KruskalMST
appkruskal = appkruskal
appkruskal_src = kruskalmst.cpp edgeweightedgraph.cpp appkruskal.cpp unionfind.cpp
appkruskal_obj = $(appkruskal_src:.cpp=.o)

# classe IndexMinHeap
appindexminheap = appindexminheap
appindexminheap_src = appindexminheap.cpp
appindexminheap_obj = $(appindexminheap_src:.cpp=.o)

# classe DijkstraSP
appdijkstra = appdijkstra
appdijkstra_src = appdijkstra.cpp dijkstrasp.cpp edgeweighteddigraph.cpp edgeweightedgraph.cpp
appdijkstra_obj = $(appdijkstra_src:.cpp=.o)

# classe AdjMatrixEdgeWeightedDigraph
appadjmatrixewdigraph = appadjmatrixewdigraph
appadjmatrixewdigraph_src = appadjmatrixewdigraph.cpp adjmatrixedgeweighteddigraph.cpp edgeweighteddigraph.cpp edgeweightedgraph.cpp
appadjmatrixewdigraph_obj = $(appadjmatrixewdigraph_src:.cpp=.o)

$(appgraph): $(appgraph_obj)
	g++ $(CPPFLAGS) $(appgraph_obj) -o $@

$(appdgraph): $(appdgraph_obj)
	g++ $(CPPFLAGS) $(appdgraph_obj) -o $@

$(appdfs): $(appdfs_obj)
	g++ $(CPPFLAGS) $(appdfs_obj) -o $@

$(appbfs): $(appbfs_obj)
	g++ $(CPPFLAGS) $(appbfs_obj) -o $@

$(appciclonaodirigido): $(appciclonaodirigido_obj)
	g++ $(CPPFLAGS) $(appciclonaodirigido_obj) -o $@

$(appciclodirigido): $(appciclodirigido_obj)
	g++ $(CPPFLAGS) $(appciclodirigido_obj) -o $@

$(apptopo): $(apptopo_obj)
	g++ $(CPPFLAGS) $(apptopo_obj) -o $@

$(appufind): $(appufind_obj)
	g++ $(CPPFLAGS) $(appufind_obj) -o $@

$(appewgraph): $(appewgraph_obj)
	g++ $(CPPFLAGS) $(appewgraph_obj) -o $@

$(appkruskal): $(appkruskal_obj)
	g++ $(CPPFLAGS) $(appkruskal_obj) -o $@

$(appindexminheap): $(appindexminheap_obj) indexminheap.h
	g++ $(CPPFLAGS) $(appindexminheap_obj) -o $@

$(appdijkstra): $(appdijkstra_obj) indexminheap.h
	g++ $(CPPFLAGS) $(appdijkstra_obj) -o $@

$(appadjmatrixewdigraph): $(appadjmatrixewdigraph_obj)
	g++ $(CPPFLAGS) $(appadjmatrixewdigraph_obj) -o $@

clean:
	-@ rm -f $(appgraph_obj) $(appgraph) $(appdgraph_obj) $(appdgraph) \
	$(appdfs_obj) $(appdfs) \
	$(appbfs_obj) $(appbfs) \
	$(appciclonaodirigido_obj) $(appciclonaodirigido) \
	$(appciclodirigido_obj) $(appciclodirigido) \
	$(apptopo_obj) $(apptopo) \
	$(appufind_obj) $(appufind) \
	$(appewgraph_obj) $(appewgraph) \
	$(appkruskal_obj) $(appkruskal) \
	$(appindexminheap) $(appindexminheap_obj) \
	$(appdijkstra) $(appdijkstra_obj) \
	$(appadjmatrixewdigraph) $(appadjmatrixewdigraph_obj)


	   	
