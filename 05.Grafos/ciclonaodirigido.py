from graph import Graph

class CicloNaoDirigido:
    def __init__(self, g):
        self.g = g
        self.marked = {}
        self.edges = set()
        self.hasCycle = False
        for v in sorted(g.getVerts()):
            if v not in self.marked:
                print("Testando",v)
                self.hasCycle = self.__containsCycle(v)
                if self.hasCycle:
                    break

    def __containsCycle(self, v):
        # print("estou em", v)
        self.marked[v] = True
        for u in self.g.getAdj(v):
            e = u + "-" + v
            # print("e:",e)
            if u not in self.marked:
                self.edges.add(e)
                res = self.__containsCycle(u)
                if res:
                    return res
            elif v + "-" + u not in self.edges:
                print(f"Ciclo detectado na aresta {v}-{u}")
                return True
        return False

if __name__ == "__main__":

    # g = Graph("exemplos/tinyG.txt")
    g = Graph();

    g.addEdge("1","2")
    g.addEdge("2","4")
    g.addEdge("4","3")
    # g.addEdge("1","3")
    g.addEdge("4","5")
    g.addEdge("6","7")
    g.addEdge("7","8")
    g.addEdge("6","8")
    uc = CicloNaoDirigido(g)

    print("Tem ciclo?", uc.hasCycle)
    print()
