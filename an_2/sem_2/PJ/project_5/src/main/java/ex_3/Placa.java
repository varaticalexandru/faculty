package ex_3;

import java.util.Arrays;

public class Placa {

    // members
    private String descriere;
    private Integer lungime;
    private Integer latime;
    private Orientare orientare;
    private Boolean[] canturi = new Boolean[4];
    private Integer nr_bucati;


    // constructors
    public Placa(String descriere, Integer lungimeMm, Integer latimeMm, Orientare orientare, Integer nrBucati) {
        this.descriere = descriere;
        lungime = lungimeMm;
        latime = latimeMm;
        this.orientare = orientare;
        nr_bucati = nrBucati;
    }

    public Placa() {}


    // getters & setters
    public String getDescriere() {
        return descriere;
    }

    public void setDescriere(String descriere) {
        this.descriere = descriere;
    }

    public Integer getLungime() {
        return lungime;
    }

    public void setLungime(Integer lungime) {
        this.lungime = lungime;
    }

    public Integer getLatime() {
        return latime;
    }

    public void setLatime(Integer latime) {
        this.latime = latime;
    }

    public Orientare getOrientare() {
        return orientare;
    }

    public void setOrientare(Orientare orientare) {
        this.orientare = orientare;
    }

    public Boolean[] getCanturi() {
        return canturi;
    }

    public void setCanturi(Boolean[] canturi) {
        this.canturi = canturi;
    }

    public Integer getNr_bucati() {
        return nr_bucati;
    }

    public void setNr_bucati(Integer nr_bucati) {
        this.nr_bucati = nr_bucati;
    }


    // methods

    @Override
    public String toString() {
        return
                "\n" +
                "Descriere: " + this.descriere + "\n" +
                "Lungime: " + this.lungime + "\n" +
                "Latime: " + this.latime + "\n" +
                "Orientare: " + this.orientare.name() + "\n" +
                "Canturi: " + Arrays.toString(this.canturi) + "\n" +
                "Nr. bucati: " + this.nr_bucati + "\n";
    }

    // arie placa
    public Integer getAriePlaca() {
        return latime * lungime;
    }

}
