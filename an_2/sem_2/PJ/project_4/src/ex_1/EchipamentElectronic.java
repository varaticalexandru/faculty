package ex_1;

import java.io.Serializable;

/**
 * Echipamentul Electronic este produsul comercializat de firma.
 * @author Admin
 * @version 1
 * @since 2023
 */
public class EchipamentElectronic implements Serializable {

    // membri
    String nume;
    String nr_inventar;
    Float pret;
    ZonaMagazie zona_magazie;
    Situatie situatie;
    String tip;

    // constructori

    /**
     * Constructorul clasei EchipamentElectronic.
     * @param nume Numele echipamentului
     * @param nr_inventar Numarul de inventar
     * @param pret Pretul
     * @param zona_magazie Zona din magazin unde este dispus
     * @param situatie Situatia echipamentului (ACHIZITIONAT / EXPUS / VANDUT)
     * @param tip Tipul echipamentului (Imrpimanta / Copiator / Sistem de calcul)
     */

    public EchipamentElectronic(String nume, String nr_inventar, Float pret, ZonaMagazie zona_magazie, Situatie situatie, String tip) {
        this.nume = nume;
        this.nr_inventar = nr_inventar;
        this.pret = pret;
        this.zona_magazie = zona_magazie;
        this.situatie = situatie;
        this.tip = tip;
    }

    // getters & setters

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getNr_inventar() {
        return nr_inventar;
    }

    public void setNr_inventar(String nr_inventar) {
        this.nr_inventar = nr_inventar;
    }

    public Float getPret() {
        return pret;
    }

    public void setPret(Float pret) {
        this.pret = pret;
    }

    public ZonaMagazie getZona_magazie() {
        return zona_magazie;
    }

    public void setZona_magazie(ZonaMagazie zona_magazie) {
        this.zona_magazie = zona_magazie;
    }

    public Situatie getSituatie() {
        return situatie;
    }

    public void setSituatie(Situatie situatie) {
        this.situatie = situatie;
    }

    public String getTip() {
        return tip;
    }

    public void setTip(String tip) {
        this.tip = tip;
    }

    // metode

    @Override
    public String toString() {
        return
            "\n\n" +
            "Nume: " + this.nume + "\n" +
            "Nr. inventar: " + this.nr_inventar + "\n" +
            "Pret: " + String.format("%.2f", this.pret) + "\n" +
            "Zona magazin: " + this.zona_magazie.toString() + "\n" +
            "Situatie: " + this.situatie.toString() + "\n"
        ;
    }
}
