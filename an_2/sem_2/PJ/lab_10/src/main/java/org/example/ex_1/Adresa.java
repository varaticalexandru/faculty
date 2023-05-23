package org.example.ex_1;

public class Adresa {

    // members
    private int nr;
    private String strada;
    private String localitate;


    // constructor
    public Adresa(int nr, String strada, String localitate) {
        this.nr = nr;
        this.strada = strada;
        this.localitate = localitate;
    }



    // getters & setters


    // methods
    @Override
    public String toString() {
        return "Adresa{" +
                "nr=" + nr +
                ", strada='" + strada + '\'' +
                ", localitate='" + localitate + '\'' +
                '}';
    }
}
