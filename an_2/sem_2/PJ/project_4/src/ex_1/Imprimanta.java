package ex_1;

import java.io.Serializable;


/**
 * Imprimanta este un subtip de echipament electronic.
 * @author Admin
 * @version 1
 * @since 2023
 */
public class Imprimanta extends EchipamentElectronic implements Serializable {

    // membri
    Integer ppm;
    String rezolutie;
    Integer p_car;
    ModTiparire mod_tiparire;


    // constructori

    /**
     * Constructorul clasei Imprimanta.
     * {@inheritDoc}
     * @param ppm Numarul de pagini / minut
     * @param rezolutie Numarul de puncte / inch
     * @param p_car Numarul de pagini / cartus
     * @param mod_tiparire / Modul de tiparire (COLOR, ALB_NEGRU)
     */
    public Imprimanta(String nume, String nr_inventar, Float pret, ZonaMagazie zona_magazie, Situatie situatie, String tip, Integer ppm, String rezolutie, Integer p_car, ModTiparire mod_tiparire) {
        super(nume, nr_inventar, pret, zona_magazie, situatie, tip);
        this.ppm = ppm;
        this.rezolutie = rezolutie;
        this.p_car = p_car;
        this.mod_tiparire = mod_tiparire;
    }


    // getters & setters
    public Integer getPpm() {
        return ppm;
    }

    public void setPpm(Integer ppm) {
        this.ppm = ppm;
    }

    public String getRezolutie() {
        return rezolutie;
    }

    public void setRezolutie(String rezolutie) {
        this.rezolutie = rezolutie;
    }

    public Integer getP_car() {
        return p_car;
    }

    public void setP_car(Integer p_car) {
        this.p_car = p_car;
    }

    public ModTiparire getMod_tiparire() {
        return mod_tiparire;
    }

    public void setMod_tiparire(ModTiparire mod_tiparire) {
        this.mod_tiparire = mod_tiparire;
    }

    // metode
    @Override
    public String toString() {
        return
            super.toString() +
            "Pagini per minut: " + this.ppm + "\n" +
            "Puncte per inch: " + this.rezolutie + "\n" +
            "Pagini per cartus: " + this.p_car + "\n" +
            "Mod tiparire: " + this.mod_tiparire.toString() + "\n" +
            "\n"
        ;
    }
}
