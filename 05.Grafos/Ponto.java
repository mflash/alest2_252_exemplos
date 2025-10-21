public class Ponto {
   
    private double x,y;

    Ponto(double x, double y) {
        setX(x);
        setY(y);
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double x) {
        this.x = x;
    }

    public void setY(double y) {
        this.y = y;
    }

    public double dist(Ponto outro) {
        return Math.sqrt(Math.pow(x-outro.x,2)
            +Math.pow(y-outro.y,2));
    }

    @Override
    public String toString() {
        return x+","+y;
    }
}
