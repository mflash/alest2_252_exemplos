import java.util.Random;

public class AppComparaCaminhosMinimos {
    public static void main(String[] args) {

        Random r = new Random();
        // EdgeWeightedDigraph g = new EdgeWeightedDigraph("tinyEWD.txt");

        // Floyd-Warshall só vai ser mais RÁPIDO
        // para grafos completos! (ligações diretas de todos para todos)

        //Digraph g = DigraphGenerator.dag(500, 500);
        Digraph g = DigraphGenerator.complete(500);

        // Cria um grafo valorado (com pesos) a partir do grafo original
        // (pesos sorteados)
        EdgeWeightedDigraph dg = new EdgeWeightedDigraph();
        for (String v : g.getVerts()) {
            for (String w : g.getAdj(v)) {
                double weight = r.nextInt(5, 30);
                dg.addEdge(v, w, weight);
            }
        }

        FloydWarshallSP fw = new FloydWarshallSP(dg);
        long tempoFW = fw.getTempoTotal();

        long tempoD = 0;
        // Para comparar, executa Dijkstra a partir de
        // CADA vértice do grafo
        for (String s : g.getVerts()) {
            long ti = System.currentTimeMillis();
            DijkstraSP d = new DijkstraSP(dg, s);
            long tf = System.currentTimeMillis();
            tempoD += (tf - ti);
        }

        System.out.println("Tempo Dijkstra      : " + tempoD);
        System.out.println("Tempo Floyd-Warshall: " + tempoFW);

    }
}