package ex_1;

public class Punct {

    // membri
    private float x;
    private float y;

    // contructor
    public Punct(float x, float y) {
        this.x = x;
        this.y = y;
    }


    // getter-e
    public float getX() {
        return x;
    }

    public float getY() {
        return y;
    }


    // setter-e
    public void setX(float x) {
        this.x = x;
    }

    public void setY(float y) {
        this.y = y;
    }

    // metode
    @Override
    public String toString() {
        return ("( " + String.format("%.2f", x) + " , " + String.format("%.2f", y) + " )");
    }

    public float getDistance(Punct p) {
        // distanta dintre punct si alt punct

        return (float) Math.sqrt( (p.getX()-x)*(p.getX()-x) + (p.getY()-y)*(p.getY()-y));
    }

    public static float getDistance(Punct p1, Punct p2) {
        // distanta dintre punct si alt punct

        return (float) Math.sqrt( (p1.getX()-p2.getX())*(p1.getX()-p2.getX()) + (p1.getY()- p2.getY())*(p1.getY()-p2.getY()));
    }

    public Punct isLower(Punct p) {
        // care punct e mai la stanga pe Ox

        if (p.x < x)
            return p;

        return this;
    }

}
