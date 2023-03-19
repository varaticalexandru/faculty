package ex_1;

public class Parabola {

    // membri
    private int a;
    private int b;
    private int c;

    // constructor
    public Parabola(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }



    // getter-e
    public int getA() {
        return a;
    }

    public int getB() {
        return b;
    }

    public int getC() {
        return c;
    }


    // setter-e
    public void setA(int a) {
        this.a = a;
    }

    public void setB(int b) {
        this.b = b;
    }

    public void setC(int c) {
        this.c = c;
    }

    // metode

    @Override
    public String toString() {
        return ("f(x) = " + a + " x^2 + " + b + " x + " + c);
    }

    public Punct getVarf() {
        return new Punct((float)-b/(2*a), (float) (-(b*b)+(4*a*c))/(4*a));
    }

    public Punct getMijloc(Parabola p) {
        // punctul de la mijlocul segmentului de dreapta ce uneste varfurile parabolelor

        Punct varf = p.getVarf();

        return new Punct((getVarf().getX()+varf.getX())/2, (getVarf().getY()+varf.getY())/2);
    }

    public static Punct getMijloc(Parabola p1, Parabola p2) {
        // punctul de la mijlocul segmentului de dreapta ce uneste varfurile parabolelor

        Punct varf_1 = p1.getVarf();
        Punct varf_2 = p2.getVarf();

        return new Punct((varf_1.getX()+varf_2.getX())/2, (varf_1.getY()+varf_2.getY())/2);
    }

    public static float getDistanta(Parabola p1, Parabola p2) {
        // distanta dintre varfurile a 2 parabole

        Punct varf_1 = p1.getVarf();
        Punct varf_2 = p2.getVarf();


        return varf_1.getDistance(varf_2);
    }

}
