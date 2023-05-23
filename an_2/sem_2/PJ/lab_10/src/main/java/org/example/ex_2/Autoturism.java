package org.example.ex_2;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class Autoturism extends Vehicul {

    // members
    private int volum_portbagaj;
    private int masa;

    // constructors
//    @Autowired
    public Autoturism(String marca, int pret, int volum_portbagaj, int masa) {
        super(marca, pret);
        this.volum_portbagaj = volum_portbagaj;
        this.masa = masa;
    }

    public Autoturism(int volum_portbagaj, int masa) {
        this.volum_portbagaj = volum_portbagaj;
        this.masa = masa;
    }

    public Autoturism() {}


    // getters & setters

    public int getVolum_portbagaj() {
        return volum_portbagaj;
    }

//    @Value("300")
    public void setVolum_portbagaj(int volum_portbagaj) {
        this.volum_portbagaj = volum_portbagaj;
    }

    public int getMasa() {
        return masa;
    }

//    @Value("1500")
    public void setMasa(int masa) {
        this.masa = masa;
    }


    // methods
    @Override
    public String toString() {
        return
                super.toString() +
                "Autoturism{" +
                "volum_portbagaj=" + volum_portbagaj +
                ", masa=" + masa +
                "} ";
    }
}
