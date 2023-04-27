package org.example.ex_2;

import com.fasterxml.jackson.annotation.JsonTypeInfo;

import java.util.Objects;

@JsonTypeInfo(use = JsonTypeInfo.Id.CLASS)
public abstract class InstrumentMuzical {

    // members
    private String producator;
    private float pret;


    // constructors
    public InstrumentMuzical() {}

    public InstrumentMuzical(String producator, float pret) {
        this.producator = producator;
        this.pret = pret;
    }


    // getters & setters
    public String getProducator() {
        return producator;
    }

    public void setProducator(String producator) {
        this.producator = producator;
    }

    public float getPret() {
        return pret;
    }

    public void setPret(float pret) {
        this.pret = pret;
    }


    // methods
    @Override
    public String toString() {
        return "InstrumentMuzical{" +
                "producator='" + producator + '\'' +
                ", pret=" + pret +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        InstrumentMuzical that = (InstrumentMuzical) o;
        return Float.compare(that.pret, pret) == 0 && Objects.equals(producator, that.producator);
    }

    @Override
    public int hashCode() {
        return Objects.hash(producator, pret);
    }

}
