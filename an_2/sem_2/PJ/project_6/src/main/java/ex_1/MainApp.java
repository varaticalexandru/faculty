package ex_1;

import java.util.ArrayList;
import java.util.List;

public class MainApp {
    public static void main(String[] args) {

        List<Angajat> angajati = new ArrayList<Angajat>();
        List<Angajat> angajati_conducere = new ArrayList<Angajat>();

        angajati = Angajat.deserialize("src/main/resources/angajati.json");

        angajati_conducere = Angajat.getListaAngajatiConducere(angajati);

        for (var a: angajati_conducere
             ) {
            System.out.println(a);
        }


    }
}
