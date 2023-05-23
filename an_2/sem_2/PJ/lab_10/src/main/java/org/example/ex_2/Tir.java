package org.example.ex_2;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

@Component
public class Tir extends Vehicul {

    // members
    @Value("30")
    private int incarcatura_max;


    // constructors
    public Tir(String marca, int pret, int incarcatura_max) {
        super(marca, pret);
        this.incarcatura_max = incarcatura_max;
    }

    public Tir(int incarcatura_max) {
        this.incarcatura_max = incarcatura_max;
    }

    public Tir() {}

    // getters & setters
    public int getIncarcatura_max() {
        return incarcatura_max;
    }

    public void setIncarcatura_max(int incarcatura_max) {
        this.incarcatura_max = incarcatura_max;
    }


    // methods

    @PostConstruct
    public void init() {
        System.out.println("init() tir");
    }

    @PreDestroy
    public void disp() {
        System.out.println("disp() tir");
    }

    @Override
    public String toString() {
        return
                super.toString() +
                "Tir{" +
                "incarcatura_max=" + incarcatura_max +
                "} ";
    }
}
