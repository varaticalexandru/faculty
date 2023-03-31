package ex_3;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class Mobilier {

    // members
    private String nume;
    private List<Placa> placi;

    // constructors
    public Mobilier(String nume, List<Placa> placi) {
        this.nume = nume;
        this.placi = placi;
    }

    public Mobilier() {}


    // getters & setters
    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public List<Placa> getPlaci() {
        return placi;
    }

    public void setPlaci(List<Placa> placi) {
        this.placi = placi;
    }


    // methods
    @Override
    public String toString() {
        return
                "\n\n" +
                "Nume: " + this.nume + "\n" +
                "Placi:\n" +
                this.placi
                + "\n";
    }

    // deserializare lista piese mobilier din .json
    public static List<Mobilier> deserializare(String filename) {

        List<Mobilier> pieseMobilier = new ArrayList<Mobilier>();

        try {
            File f = new File(filename);
            ObjectMapper mapper = new ObjectMapper();
            pieseMobilier = mapper.
                    readValue(f, new TypeReference<List<Mobilier>>() {});
        }
        catch (Exception e) {
            e.printStackTrace();
        }

        return pieseMobilier;
    }

    // serializare lista piese mobilier in .json
    public static void serializare(String filename, List<Mobilier> pieseMobilier) {
        try {
            ObjectMapper mapper = new ObjectMapper();
            File f = new File(filename);
            mapper
                    .writeValue(f, pieseMobilier);

        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

    // arie totala (suma ariilor tuturor placilor componente)
    public Integer getArieTotala() {

        int sum = 0;

        for (Placa p: this.placi
             ) {
            sum += p.getAriePlaca();
        }

        return sum;
    }

    // numar estimativ de coli de pal necesare pt. realizarea corpului de mobile
    public Integer getNrColi() {

        return ((int)Math.ceil(MainApp.ARIE_COALA / this.getArieTotala()));

    }
}
