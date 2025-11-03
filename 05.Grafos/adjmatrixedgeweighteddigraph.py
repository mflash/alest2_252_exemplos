from edgeweighteddigraph import EdgeWeightedDigraph

class AdjMatrixEdgeWeightedDigraph:
    def __init__(self, g):
        self.g = g

        self.dic = {}
        self.dic2 = {}
        self.total_vertices = len(g.getVerts())
        for idx, v in enumerate(sorted(g.getVerts())):
            self.dic[v] = idx
            self.dic2[idx] = v

        self.total_edges = 0
        self.adj = [[None for _ in range(self.total_vertices)] for _ in range(self.total_vertices)]
        for e in g.getEdges():
            self.addEdge(e)

    def mapToArray(self, v):
        return self.dic[v]

    def mapToString(self, v):
        return self.dic2[v]

    def getTotalEdges(self):
        return self.total_edges

    def addEdge(self, e):
        v = e[0]
        w = e[1]
        weight = e[2]
        v1 = self.dic[v]
        w1 = self.dic[w]
        if self.adj[v1][w1] is None:
            self.total_edges += 1
            self.adj[v1][w1] = weight

    def getAdj(self, v):
        return self.g.getAdj(v)

    def toDot(self):
        return self.g.toDot()

    def __str__(self):
        lines = []
        header = "  " + " ".join(f"{i:<5}" for i in range(self.total_vertices))
        lines.append(header)
        for i in range(self.total_vertices):
            row = [f"{i}"]
            for j in range(self.total_vertices):
                weight = self.adj[i][j]
                if weight:
                    row.append(f"{weight:5.2f}")
                else:
                    row.append("-----")
            lines.append(" ".join(row))
        return "\n".join(lines)


# Exemplo de uso:
if __name__ == "__main__":
    g = EdgeWeightedDigraph("exemplos/tinyEWD.txt")
    ag = AdjMatrixEdgeWeightedDigraph(g)
    print(ag.toDot())
    print(ag)

