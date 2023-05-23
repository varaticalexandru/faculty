package org.example.ex_0;

public class Dreptunghi {

    // members
    private int lungime;
    private int latime;




    // constructors
    public Dreptunghi(int lungime, int latime) {
        this.lungime = lungime;
        this.latime = latime;
    }


    // getters & setters

    public int getLungime() {
        return lungime;
    }

    public void setLungime(int lungime) {
        this.lungime = lungime;
    }

    public int getLatime() {
        return latime;
    }

    public void setLatime(int latime) {
        this.latime = latime;
    }


    // methods

    public void aria() {
        System.out.println("Aria dreptunghi: " + (lungime * latime));
    }

}
