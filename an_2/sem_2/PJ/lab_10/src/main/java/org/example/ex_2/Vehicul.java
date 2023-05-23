package org.example.ex_2;

import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.core.io.Resource;
import org.springframework.stereotype.Component;

@Component
public class Vehicul {

    // members
    @Value("MAN")
    private String marca;

    @Value("100000")
    private int pret;

    // constructors
//    @Autowired
    public Vehicul(String marca, int pret) {
        this.marca = marca;
        this.pret = pret;
    }

    public Vehicul() {}

    // getters & setters
    public String getMarca() {
        return marca;
    }

//    @Value("Mercedes")
    public void setMarca(String marca) {
        this.marca = marca;
    }

    public int getPret() {
        return pret;
    }

//    @Value("32000")
    public void setPret(int pret) {
        this.pret = pret;
    }


    // methods


    @Override
    public String toString() {
        return "Vehicul{" +
                "marca='" + marca + '\'' +
                ", pret=" + pret +
                '}';
    }
}
