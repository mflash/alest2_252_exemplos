// Algoritmo de árvore geradora mínima

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class KruskalMST {
    
    private List<Edge> mst;
    
    KruskalMST(EdgeWeightedGraph g)
    {
       mst = new ArrayList<>(); 
       UnionFind uf = new UnionFind(g);
       List<Edge> edges = new ArrayList<>();
       for(Edge e: g.getEdges()) {
            edges.add(e);
       }
       // Ordena as arestas em ordem crescente de peso
       Collections.sort(edges);
       for(Edge e: edges) {
            String v = e.getV();
            String w = e.getW();
            // Se v e w não estiverem no mesmo conjunto
            // (usar essa aresta NÃO formará ciclo)
            // adiciona a aresta à árvore geradora
            if(!uf.find(v).equals(uf.find(w))) {
                mst.add(e);
                // Inclui w no conjunto de v
                uf.union(v, w);
                e.setColor("color=red penwidth=3");
                // Se já tivermos arestas suficientes, podemos
                // parar!
                if(mst.size() == g.getTotalVerts()-1)
                    break;
            }
       }
    }

    Iterable<Edge> getMST() {
        return mst;
    }

    public static void main(String[] args) {
        EdgeWeightedGraph g = new EdgeWeightedGraph("exemplos/tinyEWG.txt");
        KruskalMST k = new KruskalMST(g);
        for(Edge e: k.getMST())
            System.out.println(e);
        System.out.println();
        System.out.println(g.toDot());
    }
}
