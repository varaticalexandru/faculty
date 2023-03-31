package ex_3;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MainApp {

    public static final Float ARIE_COALA = 5.796f;

    // menu interactiv
    public static void menu() {

        System.out.println(
        """
            ----- Meniu Interactiv -----
            0. Iesire
            1. Deserializare piese de mobilier din .json
            2. Serializare piese de mobilier in .json
            3. Afisare piese de mobilier si placi componente
            4. Afisare caracteristicile placilor care compun o anumita piesa de mobilier
            5. Afiseaza estimativ numarul colilor de pal necesare pentru realizare unui anumit corp de mobile
            -----------------------------"""
            + "\nOptiunea dvs: "
        );
    }

    // functie main
    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(System.in);
        List<Mobilier> pieseMobilier = new ArrayList<Mobilier>();
        String filename = "src\\main\\resources\\mobilier.json";

        int opt = 0;

        do {
            menu();
            opt = scanner.nextInt();

            switch (opt) {
                case 0: {   // iesire
                    System.exit(0);

                    break;
                }

                case 1: {   // deserializare
                    pieseMobilier = Mobilier.deserializare(filename);

                    break;
                }

                case 2: {   // serializare
                    Mobilier.serializare(filename, pieseMobilier);

                    break;
                }

                case 3: {   // afisare piese de mobilier si placi componente
                    for (Mobilier m: pieseMobilier
                         ) {
                        System.out.println(m);
                    }

                    break;
                }

                case 4: {   // afisare caracteristici placi care compun o anumita piesa de mobilier

                    System.out.print("Introduceti numele piesei de mobilier cautate: ");
                    Scanner scanner1 = new Scanner(System.in);
                    String lookedUp = scanner1.nextLine();
                    boolean found = false;

                    for (Mobilier m: pieseMobilier
                         ) {
                        if (m.getNume().compareTo(lookedUp) == 0) {
                            found = true;
                            System.out.println(m);
                        }
                    }

                    if (!found)
                        System.out.println("\nPiesa de mobilier inexistenta !\n");

                    break;
                }

                case 5: {   // afisare estimativa numar coli de pal necesare

                    System.out.print("Introduceti numele piesei de mobilier cautate: ");
                    Scanner scanner1 = new Scanner(System.in);
                    String lookedUp = scanner1.nextLine();
                    boolean found = false;

                    for (Mobilier m: pieseMobilier
                    ) {
                        if (m.getNume().compareTo(lookedUp) == 0) {
                            found = true;
                            System.out.println("Nr. coli de pal necesare: " + m.getNrColi());;
                        }
                    }

                    if (!found)
                        System.out.println("\nPiesa de mobilier inexistenta !\n");

                    break;
                }
            }


        }
        while (opt != 0);



        System.out.println(pieseMobilier);

    }
}
