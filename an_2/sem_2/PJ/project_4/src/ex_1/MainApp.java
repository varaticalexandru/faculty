package ex_1;

import com.sun.tools.javac.Main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainApp {

    // citeste echipamentele
    public static List<EchipamentElectronic> getEchipamente(String file_in) throws IOException {

        List<EchipamentElectronic> echipamente = new ArrayList<EchipamentElectronic>();
        BufferedReader br = new BufferedReader(new FileReader(file_in));

        String line;

        // citim fiecare linie din fisier
        while ((line = br.readLine()) != null && !line.isBlank()) {

            String[] data = line.split(";");

            // caracteristici comune
            String nume = data[0].trim();
            String nr_inventar = data[1].trim();
            Float pret = Float.parseFloat(data[2].trim());
            ZonaMagazie zona_magazie = ZonaMagazie.valueOf(data[3].trim().toUpperCase());
            Situatie situatie = Situatie.valueOf(data[4].trim().toUpperCase());
            String tip = data[5].trim();

            if (tip.compareTo("imprimanta") == 0) {
                Integer ppm = Integer.parseInt(data[6].trim());
                String rezolutie = data[7].trim();
                Integer p_car = Integer.parseInt(data[8].trim());
                ModTiparire mod_tiparire = ModTiparire.valueOf(data[9].trim().toUpperCase());

                // apelare constructor Imprimanta
                Imprimanta i = new Imprimanta(nume, nr_inventar, pret, zona_magazie, situatie, tip, ppm, rezolutie, p_car, mod_tiparire);

                // adaugare la lista
                echipamente.add(i);
            }
            else if (tip.compareTo("copiator") == 0) {
                Integer p_ton = Integer.parseInt(data[6].trim());
                FormatCopiere format_copiere = FormatCopiere.valueOf(data[7].trim().toUpperCase());

                // apelare constructor Copiator
                Copiator c = new Copiator(nume, nr_inventar, pret, zona_magazie, situatie, tip, p_ton, format_copiere);

                // adaugare la lista
                echipamente.add(c);
            }
            else if (tip.compareTo("sistem de calcul") == 0){
                String tip_monitor = data[6].trim();
                Float viteza_proc = Float.parseFloat(data[7].trim());
                Integer capacit_hdd = Integer.parseInt(data[8].trim());
                SistemOperare sistem_operare = SistemOperare.valueOf(data[9].trim().toUpperCase());

                // apelare constructor SistemCalcul
                SistemCalcul s = new SistemCalcul(nume, nr_inventar, pret, zona_magazie, situatie, tip, tip_monitor, viteza_proc, capacit_hdd, sistem_operare);

                // adaugare la lista
                echipamente.add(s);
            }
        }

        br.close();
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
                --------------------------------------------
                Optiunea dvs:""" + " "
        );
    }

    // afiseaza toate echipamentele
    public static void afisareEchipamente(List<EchipamentElectronic> echipamente)
    {
        System.out.println("Toate echipamentele:");
        for (EchipamentElectronic echipament: echipamente
             ) {
            System.out.println(echipament);
        }

    }

    // afiseaza toate echipamentele de un anumit tip
    public static void afisareEchipamenteTip(List<EchipamentElectronic> echipamente, String tip)
    {
        System.out.println("Echipamtele de tip " + tip + ":");

        for (EchipamentElectronic echipament: echipamente
             ) {
            if (echipament.getClass().getSimpleName().compareTo(tip) == 0)
                System.out.println(echipament);
        }
    }



    public static void main(String[] args) throws IOException {

        String in_file = "src\\ex_1\\echipamente.txt";
        BufferedReader br = new BufferedReader(new FileReader(in_file));
        Scanner scanner = new Scanner(System.in);

        List<EchipamentElectronic> echipamente = new ArrayList<EchipamentElectronic>();
        echipamente = getEchipamente(in_file);

        Integer opt = 0;

        do {
            menu();
            opt = Integer.parseInt(scanner.nextLine());

            switch (opt)
            {
                case 0:     // iesire
                {
                    System.exit(0);

                    break;
                }

                case 1:     // afisarea tuturor echipamentelor
                {
                    MainApp.afisareEchipamente(echipamente);

                    break;
                }

                case 2:     // afisare imprimante
                {
                    MainApp.afisareEchipamenteTip(echipamente, "Imprimanta");

                    break;
                }

                case 3:     // afisare copiatoare
                {
                    MainApp.afisareEchipamenteTip(echipamente, "Copiator");

                    break;
                }

                case 4:     // afisare sisteme de calcul
                {
                    MainApp.afisareEchipamenteTip(echipamente, "SistemCalcul");

                    break;
                }

                case 5:     // modificarea starii in care se afla un echipament
                {

                }

                default:
                {
                    break;
                }
            }

        }
        while(opt != 0);


        scanner.close();
        br.close();
    }
}
