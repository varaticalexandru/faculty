package ex_2;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Produs {

    // membri
    static float incasari;
    String nume;
    float pret;
    int cantitate;
    LocalDate dataExpirare;


    // constructor
    public Produs(String nume, float pret, int cantitate, LocalDate data_expirare) {
        this.nume = nume;
        this.pret = pret;
        this.cantitate = cantitate;
        this.dataExpirare = data_expirare;
    }


    // getter-i
    public static float getIncasari() {
        return incasari;
    }

    public String getNume() {
        return nume;
    }

    public float getPret() {
        return pret;
    }

    public int getCantitate() {
        return cantitate;
    }

    public LocalDate getDataExpirare() {
        return dataExpirare;
    }


    // setter-i
    public static void setIncasari(float incasari) {
        Produs.incasari = incasari;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public void setPret(float pret) {
        this.pret = pret;
    }

    public void setCantitate(int cantitate) {
        this.cantitate = cantitate;
    }

    public void setDataExpirare(LocalDate dataExpirare) {
        this.dataExpirare = dataExpirare;
    }

    // metode
    @Override
    public String toString() {
        return nume+", "+String.format("%.2f", pret)+", "+cantitate+", "+dataExpirare;
    }

    public boolean isExpirat() {
        return ( ChronoUnit.DAYS.between(LocalDate.now(), dataExpirare) < 0 );
    }

}
