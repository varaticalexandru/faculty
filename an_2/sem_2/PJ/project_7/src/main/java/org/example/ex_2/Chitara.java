package org.example.ex_2;

import java.util.Objects;

public class Chitara extends InstrumentMuzical {

    // members
    private TipChitara tip_chitara;
    private int nr_corzi;



    // constructors
    public Chitara() {}

    public Chitara(String producator, float pret, TipChitara tip_chitara, int nr_corzi) {

        super(producator, pret);
        this.tip_chitara = tip_chitara;
        this.nr_corzi = nr_corzi;
    }


    // setters & getters
    public TipChitara getTip_chitara() {
        return tip_chitara;
    }

    public void setTip_chitara(TipChitara tip_chitara) {
        this.tip_chitara = tip_chitara;
    }

    public int getNr_corzi() {
        return nr_corzi;
    }

    public void setNr_corzi(int nr_corzi) {
        this.nr_corzi = nr_corzi;
    }



    // methods
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        if (!super.equals(o)) return false;
        Chitara chitara = (Chitara) o;
        return nr_corzi == chitara.nr_corzi && tip_chitara == chitara.tip_chitara;
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), tip_chitara, nr_corzi);
    }

    @Override
    public String toString() {
        return
                super.toString() + ": Chitara{" +
                "tip_chitara=" + tip_chitara +
                ", nr_corzi=" + nr_corzi +
                "} ";
    }
}
