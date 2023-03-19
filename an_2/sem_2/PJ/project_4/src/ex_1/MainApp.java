package ex_1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MainApp {

    // citeste echipamentele
    public static List<EchipamentElectronic> getEchipamente(String file_in) throws IOException {

        List<EchipamentElectronic> echipamente = new ArrayList<EchipamentElectronic>();
        BufferedReader br = new BufferedReader(new FileReader(file_in));

        String line;

        // citim fiecare linie din fisier
        while ((line = br.readLine()) != null) {

            String[] data = line.split(";");

            // caracteristici comune
            String nume = data[0].trim();
            String nr_inventar = data[1].trim();
            Float pret = Float.parseFloat(data[2].trim());
            ZonaMagazie zona_magazie = ZonaMagazie.valueOf(data[3].trim().toUpperCase());
            Situatie situatie = Situatie.valueOf(data[4].trim().toUpperCase());
            String tip = data[5].trim();

            if (tip == "imprimanta") {
                Integer ppm = Integer.parseInt(data[6].trim());
                String rezolutie = data[7].trim();
                Integer p_car = Integer.parseInt(data[8].trim());
                ModTiparire mod_tiparire = ModTiparire.valueOf(data[9].trim());

                // apelare constructor Imprimanta
                Imprimanta i = new Imprimanta(nume, nr_inventar, pret, zona_magazie, situatie, ppm, rezolutie, p_car, mod_tiparire);

                // adaugare la lista
                echipamente.add(i);
            }
            else if (tip == "copiator") {
                Integer p_ton = Integer.parseInt(data[10].trim());
                FormatCopiere format_copiere = FormatCopiere.valueOf(data[11].trim());

                // apelare constructor Copiator
                Copiator c = new Copiator(nume, nr_inventar, pret, zona_magazie, situatie, p_ton, format_copiere);

                // adaugare la lista
                echipamente.add(c);
            }
            else if (tip == "sistem de calcul"){
                String tip_monitor = data[12].trim();
                Float viteza_proc = Float.parseFloat(data[13].trim());
                Integer capacit_hdd = Integer.parseInt(data[14].trim());
                SistemOperare sistem_operare = SistemOperare.valueOf(data[15].trim());

                // apelare constructor SistemCalcul
                SistemCalcul s = new SistemCalcul(nume, nr_inventar, pret, zona_magazie, situatie, tip_monitor, viteza_proc, capacit_hdd, sistem_operare);

                // adaugare la lista
                echipamente.add(s);
            }
        }

        return echipamente;
    }

    // menu
    public static void menu() {
        System.out.println(
            """
                ------------ Meniu Interactiv ------------
                0. Iesire
                1. Afisarea tuturor echipamentelor
                2. Afisarea imprimantelor
                3. Afisarea copiatoarelor
                4. Afisarea sistemelor de calcul
                5. Modificarea starii in care se afla un echipament
                6. Setarea unui anumit mod de scriere pentru o imprimantă
                7. Setarea unui format de copiere pentru copiatoare
                8. Instalarea unui anumit sistem de operare pe un sistem de calcul
                9. Afisarea echipamentelor vandute
                10. Serializarea colectiei de obiecte in fisierul echip.bin
                11. Deserializarea colectiei de obiecte in fisierul echip.bin
            """
        );
    }



    public static void main(String[] args) throws IOException {

        String in_file = "src\\ex_1\\echipamente.txt";
        List<EchipamentElectronic> echipamente = new ArrayList<EchipamentElectronic>();

        echipamente = getEchipamente(in_file);
    }
}
