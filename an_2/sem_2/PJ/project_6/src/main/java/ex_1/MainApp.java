package ex_1;

import java.util.ArrayList;
import java.util.List;

public class MainApp {
    public static void main(String[] args) {

        List<Angajat> angajati = new ArrayList<Angajat>();
        List<Angajat> angajati_nonconducere = new ArrayList<Angajat>();

        angajati = Angajat.deserialize("src/main/resources/angajati.json");

        Angajat.afisareNrPersAngajataVaraTrecuta(angajati);

    }
}
