package ex_1;

import com.sun.tools.javac.Main;

import java.io.*;
import java.sql.Array;
import java.sql.SQLOutput;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * Clasa principala aplicatie
 */
public class MainApp {

    /**
     * Citeste echipamentele din fisier
     * @param file_in Numele fisierului de intrare
     * @return Lista de obiecte citita din fisier
     */
    public static List<EchipamentElectronic> getEchipamente(String file_in) throws IOException
    {

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


    /**
     * Afiseaza meniul interactiv
     */
    public static void menu()
    {
        System.out.println(
            """
                ------------ Meniu Interactiv ------------
                0. Iesire
                1. Afisarea tuturor echipamentelor
                2. Afisarea imprimantelor
                3. Afisarea copiatoarelor
                4. Afisarea sistemelor de calcul
                5. Modificarea situatiei in care se afla un echipament
                6. Setarea unui anumit mod de scriere pentru o imprimantă
                7. Setarea unui format de copiere pentru copiatoare
                8. Instalarea unui anumit sistem de operare pe un sistem de calcul
                9. Afisarea echipamentelor vandute
                10. Serializarea colectiei de obiecte in fisier .bin
                11. Deserializarea colectiei de obiecte din fisier .bin
                --------------------------------------------
                Optiunea dvs:""" + " "
        );
    }


    /**
     * Afiseaza toate echipamentele
     * @param echipamente Lista de echipamente
     */
    public static void afisareEchipamente(List<EchipamentElectronic> echipamente)
    {
        System.out.println("Toate echipamentele:");
        for (EchipamentElectronic echipament: echipamente
             ) {
            System.out.println(echipament);
        }

    }


    /**
     * Afiseaza toate echipamentele de un anumit tip
     * @param echipamente Lista de echipamente
     * @param tip Tipul de echipamente
     */
    public static void afisareEchipamenteTip(List<EchipamentElectronic> echipamente, String tip)
    {
        System.out.println("Echipamtele de tip " + tip + ":");

        for (EchipamentElectronic echipament: echipamente
             ) {
            if (echipament.getClass().getSimpleName().compareTo(tip) == 0)
                System.out.println(echipament);
        }
    }


    /**
     * Modificare valoare parametru echipament
     * @param echipamente Lista de echipamente
     * @param nr_inventar Numarul de inventar al echipamentului
     * @param parametru Numele parametrului
     * @param valoare Valoarea parametrului
     */
    public static void modificareParametruEchipament(List<EchipamentElectronic> echipamente, String nr_inventar, String parametru, String valoare)
    {
        int found = 0;

        switch (parametru) {
            case "situatie":   // 5
            {
                for (EchipamentElectronic e: echipamente
                     ) {
                    if (e.getNr_inventar().equals(nr_inventar)) {
                        found = 1;
                        e.setSituatie(Situatie.valueOf(valoare.toUpperCase()));   // set situatie
                        System.out.println("Stare modificata !");
                    }
                }

                break;
            }

            case "mod_tiparire":    // 6
            {
                for (EchipamentElectronic e: echipamente
                     ) {
                    if (e instanceof Imprimanta && e.getNr_inventar().compareTo(nr_inventar) == 0) {
                        found = 1;
                        ((Imprimanta) e).setMod_tiparire(ModTiparire.valueOf(valoare.toUpperCase()));     // set mod_tiparire
                        System.out.println("Mod Tiparire modificat !");
                    }
                }

                break;
            }

            case "format_copiere":    // 7
            {
                for (EchipamentElectronic e: echipamente
                     ) {
                    if (e instanceof Copiator && e.getNr_inventar().compareTo(nr_inventar) == 0) {
                        found = 1;
                        ((Copiator) e).setFormat_copiere(FormatCopiere.valueOf(valoare.toUpperCase()));   // set format_copiere
                        System.out.println("Format Copiere modificat !");
                    }
                }

                break;
            }

            case "sistem_operare":    // 8
            {
                for (EchipamentElectronic e: echipamente
                     ) {
                    if (e instanceof SistemCalcul && e.getNr_inventar().compareTo(nr_inventar) == 0) {
                        found = 1;
                        ((SistemCalcul) e).setSistem_operare(SistemOperare.valueOf(valoare.toUpperCase()));     // set sistem_operare
                        System.out.println("Sistem Operare modificat !");
                    }
                }
            }

            break;
        }


        if (found == 0)
            System.out.println("Echipament inexistent, numar inventar invalid !");
    }

    /**
     * Afisarea echipamentelor vandute
     * @param echipamente Lista de echipamente
     */
    public static void afisareEchipamenteVandute(List<EchipamentElectronic> echipamente)
    {

        System.out.println("\nEchipamente vandute: ");
        for (EchipamentElectronic e: echipamente
             ) {
            if (e.getSituatie() == Situatie.VANDUT)
                System.out.println(e);
        }
    }


    /**
     * Serializare lista de echipamente in fisier .bin
     * @param echipamente Lista de echipamente
     * @param filename Numele fisierului
     */
    public static void serializeBin(List<EchipamentElectronic> echipamente, String filename) throws IOException
    {

        try {
            FileOutputStream f = new FileOutputStream(filename);
            ObjectOutputStream oos = new ObjectOutputStream(f);

            oos.writeObject(echipamente);   // serializare
            oos.close();
            f.close();
        }
        catch (IOException e) {
            e.printStackTrace();
        }

    }


    /**
     * Deserializare lista de echipamente din fisier .bin
     * @param filename Numele fisierului
     * @return Lista de echipamente
     */
    public static List<EchipamentElectronic> deserializeBin(String filename) throws IOException
    {

        List<EchipamentElectronic> echipamente = new ArrayList<EchipamentElectronic>();

        try {
            FileInputStream f = new FileInputStream(filename);
            ObjectInputStream ois = new ObjectInputStream(f);

            echipamente = (List<EchipamentElectronic>) ois.readObject();     // deserializare

            f.close();
            ois.close();

        }
        catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }

        return echipamente;
    }


    /**
     * Functia main
     * @param args Argumente din linia de comanda
     */
    public static void main(String[] args) throws IOException {

        String in_file = "src\\ex_1\\echipamente.txt";
        BufferedReader br = new BufferedReader(new FileReader(in_file));
        Scanner scanner = new Scanner(System.in);

        List<EchipamentElectronic> echipamente = new ArrayList<EchipamentElectronic>();
        echipamente = getEchipamente(in_file);

        int opt = 0;

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

                case 5:     // modificarea situatiei in care se afla un echipament
                {

                    System.out.println("\nIntroduceti nr. de inventar si situatia dorita:\n");
                    modificareParametruEchipament(echipamente, scanner.nextLine(), "situatie", scanner.nextLine());
                    break;
                }

                case 6:     // setarea modului de tiparire pentru o imprimanta
                {

                    System.out.println("\nIntroduceti nr. de inventar si modul de tiparire dorit:\n");
                    modificareParametruEchipament(echipamente, scanner.nextLine(), "mod_tiparire", scanner.nextLine());
                    break;
                }

                case 7:     // setarea formatului de copiere pentru o imprimanta
                {

                    System.out.println("\nIntroduceti nr. de inventar si formatul de copiere dorit:\n");
                    modificareParametruEchipament(echipamente, scanner.nextLine(), "format_copiere", scanner.nextLine());
                    break;
                }

                case 8:     // setarea sistemului de operare pentru un sistem de calcul
                {
                    System.out.println("\nIntroduceti nr. de inventar si sistemul de operare dorit:\n");
                    modificareParametruEchipament(echipamente, scanner.nextLine(), "sistem_operare", scanner.nextLine());
                    break;
                }

                case 9:     // afisarea echipamentelor vandute
                {
                    afisareEchipamenteVandute(echipamente);

                    break;
                }

                case 10:    //  serializarea colectiei de obiecte in fisier .bin
                {
                    serializeBin(echipamente, "echipamente.bin");

                    break;
                }

                case 11:    //  deserializarea colectiei de obiecte din fisierul .bin
                {
                    echipamente = deserializeBin("echipamente.bin");

                    break;
                }

                default:
                {
                    System.out.println("Eroare ! Optiune nedefinita !");
                    break;
                }
            }

        }
        while(opt != 0);


        scanner.close();
        br.close();
    }
}
