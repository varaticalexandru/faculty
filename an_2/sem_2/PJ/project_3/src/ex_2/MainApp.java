package ex_2;

import java.io.*;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainApp {

    public static void salvareProduse(List<Produs> produse, String out_file) throws IOException {

        BufferedWriter bw = new BufferedWriter(new FileWriter(out_file));
        Scanner scanner = new Scanner(System.in);

        System.out.print("\nIntroduceti cantitatea indicata: ");
        int cantitate = scanner.nextInt();

        for (Produs p: produse
             ) {
            if (p.getCantitate() < cantitate)
                bw.append(p.getNume()+", "+p.getPret()+", "+p.getCantitate()+", "+p.getDataExpirare()+"\n");
        }

        bw.close();
    }
    public static void afisareProduse(List<Produs> produse) {
        System.out.println("\nToate produsele:\n");
        for (Produs p: produse
        ) {
            System.out.println(p);
        }
        System.out.println();
    }
    public static void afisareProduseExpirate(List<Produs> produse) {
        System.out.println("\nProdusele expirate:\n");
        for (Produs p: produse
        ) {
            if (p.isExpirat() == true)
                System.out.println(p+" | data expirarii: "+p.getDataExpirare());
        }
        System.out.println();
    }
    public static void showMenu() {
        System.out.print("\n"+"""
                -------- Meniu Interactiv --------
                0. Iesire
                1. Afisarea tuturor produselor
                2. Afisarea produselor expirate
                3. Vanzarea unui produs
                4. Afisarea produselor cu pretul minim
                5. Salvarea produselor care au o cantitate mai mica ca o valoare indicata
                6. Afisare incasari
                -----------------------------------
                Optiunea dvs:"""+" "
    );
    }
    public static void vindeProdus(List<Produs> produse) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Introduceti numele produsului vandut: ");
        String nume = scanner.nextLine();
        int found = -1;

        label:
        for (Produs p: produse
             ) {
            if (p.getNume().compareTo(nume) == 0) { // gasit
                found = 1;

                System.out.print("Introduceti cantitatea dorita: ");
                int cantitate = scanner.nextInt();

                if (cantitate <= p.getCantitate()) { // disponibil
                    p.setCantitate(p.getCantitate() - cantitate);   // decrementare stoc
                    Produs.setIncasari(Produs.getIncasari() + p.getPret()*cantitate);  // incrementare incasari
                }
                else {
                    System.out.println("Eroare ! Stoc insuficient !");
                    break label;
                }

                if (p.getCantitate() == 0) {    // stoc epuizat
                    System.out.println("Stoc epuizat, produs eliminat !");
                    produse.remove(p);  // stergere produs din lista
                }

            }
        }

    }
    public static void afisareProdusePretMinim(List<Produs> produse) {

        float pret_min = Integer.MAX_VALUE;

        // cautare pret minim
        for (Produs p: produse
             ) {
            if (p.getPret() < pret_min)
                pret_min = p.getPret();
        }

        // afisare toate produsele cu pretul minim
        System.out.println("\nProdusele cu pret minim:");
        for (Produs p: produse
             ) {
            if (p.getPret() == pret_min)
                System.out.println(p);
        }
        System.out.println();
    }
    public static List<Produs> getProduse(String in_file) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(in_file));
        List produse = new ArrayList<Produs>();

        String record;

        // citeste toate liniile din in_file
        while ((record = br.readLine()) != null) {

            String[] date = record.split(",");
            LocalDate dataExpirare = LocalDate.parse(date[3].trim(), DateTimeFormatter.ofPattern("yyyy-MM-dd"));
            produse.add(new Produs(date[0].trim(), Float.parseFloat(date[1].trim()), Integer.parseInt(date[2].trim()), dataExpirare));
        }

        br.close();

        return produse;
    }
    public static void main(String[] args) throws IOException {

        String file_in = "src\\ex_2\\produse.csv";
        String file_out = "src\\ex_2\\produse_out.csv";

        Scanner scanner = new Scanner(System.in);
        List<Produs> produse = new ArrayList<Produs>(); // lista produse

        produse = getProduse(file_in);

        int opt = 0;    // optiune

        do {
            showMenu();
            opt = scanner.nextInt();
            switch (opt) {

                case 0: {   // iesire
                    System.exit(0);

                    break;
                }

                case 1: {   // afisarea tuturor produselor
                    afisareProduse(produse);

                    break;
                }

                case 2: {   // afisarea produselor expirate
                    afisareProduseExpirate(produse);

                    break;
                }

                case 3: {   // Vanzarea unui produs
                        vindeProdus(produse);

                    break;
                }

                case 4: {   // afisarea produselor cu pretul minim
                    afisareProdusePretMinim(produse);

                    break;
                }

                case 5: {   // salvarea produselor care au o cantitate mai mica ca o valoare indicata
                    salvareProduse(produse, file_out);

                    break;
                }

                case 6: {   // afisare incasari
                    System.out.println("\nIncasari: "+Produs.getIncasari());

                    break;
                }

                default: {  // default
                    break;
                }
            }

        } while(opt != 0);

    }
}
