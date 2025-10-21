import java.util.ArrayList;

public class AppMapa {
   
    public static void main(String[] args) {
        ArrayList<Ponto> pontos = new ArrayList<>();
        In arq = new In("dados.csv");
        //Enquanto há linhas no arquivo...
        while(arq.hasNextLine()) {
            String linha = arq.readLine();
            // Quebra no ";"
            String[] coords = linha.split(";");
            // Primeiro campo é latitude (y), segundo é longitude (x)
            double y = Double.parseDouble(coords[0]);
            double x = Double.parseDouble(coords[1]);
            //System.out.println(y+", "+x);
            pontos.add(new Ponto(x,y));
        }
        EdgeWeightedGraph g = new EdgeWeightedGraph();
        // Passa por cada ponto
        for(int v=0; v<pontos.size(); v++) {
            double menorDist = 10000000;
            int posMenor = 0;
            // E calcula a distância para todos os demais
            // (exceto ele!)
            for(int w=0; w<pontos.size(); w++) {
                // Mesmo vértice? Pula
                if(v == w) continue;
                Ponto pontoV = pontos.get(v);
                Ponto pontoW = pontos.get(w);
                double dist = pontoV.dist(pontoW);
                if(dist < menorDist) {
                    posMenor = w; // pos é o número do vértice
                    menorDist = dist;
                }
            } 
            // Neste ponto, menorDist armazena a menor distância
            // e posMenor armazena o ÍNDICE do ponto com a menor
            // distância - basta criar uma aresta então
            g.addEdge(v+"", posMenor+"", menorDist);
        }
        // Teste: gera a saída com todas as arestas
        // (na realidade precisa rodar Kruskal e gerar as arestas
        // que fazem parte da árvore com "1" no final)
        for(Edge e: g.getEdges()) {
            System.out.println(e.getV()+" "+e.getW()+" 0");
            //System.out.println(e);
        }
    }
}
