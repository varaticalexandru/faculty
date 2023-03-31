package ex_1;

import java.io.Serializable;


/**
 * Sistemul de calcul este un subtip de echipament electronic.
 * @author Admin
 * @version 1
 * @since 2023
 */
public class SistemCalcul extends EchipamentElectronic implements Serializable {

    // membri
    String tip_monitor;
    Float viteza_proc;
    Integer capacit_hdd;
    SistemOperare sistem_operare;

    /**
     * Constructorul clasei SistemCalcul.
     * {@inheritDoc}
     * @param tip_monitor Tipul monitorului
     * @param viteza_proc Viteza de procesare (GHz)
     * @param capacit_hdd Capacitatea HDD-ului
     * @param sistem_operare Sistemul de operare (WINDOWS / LINUX)
     */
    public SistemCalcul(String nume, String nr_inventar, Float pret, ZonaMagazie zona_magazie, Situatie situatie, String tip, String tip_monitor, Float viteza_proc, Integer capacit_hdd, SistemOperare sistem_operare) {
        super(nume, nr_inventar, pret, zona_magazie, situatie, tip);
        this.tip_monitor = tip_monitor;
        this.viteza_proc = viteza_proc;
        this.capacit_hdd = capacit_hdd;
        this.sistem_operare = sistem_operare;
    }


    // constructori


    // getters & setters
    public String getTip_monitor() {
        return tip_monitor;
    }

    public void setTip_monitor(String tip_monitor) {
        this.tip_monitor = tip_monitor;
    }

    public Float getViteza_proc() {
        return viteza_proc;
    }

    public void setViteza_proc(Float viteza_proc) {
        this.viteza_proc = viteza_proc;
    }

    public Integer getCapacit_hdd() {
        return capacit_hdd;
    }

    public void setCapacit_hdd(Integer capacit_hdd) {
        this.capacit_hdd = capacit_hdd;
    }

    public SistemOperare getSistem_operare() {
        return sistem_operare;
    }

    public void setSistem_operare(SistemOperare sistem_operare) {
        this.sistem_operare = sistem_operare;
    }

    @Override
    public String toString() {
        return
            super.toString() +
            "Tip monitor: " + this.tip_monitor + "\n" +
            "Viteza procesor: " + this.viteza_proc + "\n" +
            "Capacitate HDD" + this.capacit_hdd + "\n" +
            "Sistem de operare: " + this.sistem_operare.toString() + "\n" +
            "\n"
        ;
    }
}
