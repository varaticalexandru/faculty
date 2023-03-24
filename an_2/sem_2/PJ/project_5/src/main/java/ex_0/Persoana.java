package ex_0;

public class Persoana {

    // members
    private String nume;
    private int varsta;

    // constructors

    public Persoana(String nume, int varsta) {
        this.nume = nume;
        this.varsta = varsta;
    }

    public Persoana() {}


    // getters & setters
    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public int getVarsta() {
        return varsta;
    }

    public void setVarsta(int varsta) {
        this.varsta = varsta;
    }



    @Override
    public String toString() {
        return nume + ", " + varsta;
    }
}
