package org.example.ex_2;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import javax.annotation.*;

//@Component
public class Motocicleta extends Vehicul {

    // members
    private int vmax;


    // constructors
//    @Autowired
    public Motocicleta(String marca, int pret, int vmax) {
        super(marca, pret);
        this.vmax = vmax;
    }

    public Motocicleta(int vmax) {
        this.vmax = vmax;
    }

    public Motocicleta() {
    }

    // getters & setters

    public int getVmax() {
        return vmax;
    }

    public void setVmax(int vmax) {
        this.vmax = vmax;
    }

    // methods
    @Override
    public String toString() {
        return
                super.toString() +
                "Motocicleta{" +
                "vmax=" + vmax +
                "} ";
    }


    @PostConstruct
    void init() {
        System.out.println("init() motocicleta");
    }

    @PreDestroy
    void disp() {
        System.out.println("disp() motocicleta");
    }
}
