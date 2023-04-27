package ex_4;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.Scanner;
import java.time.Year;
import java.util.regex.Pattern;

public class MainApp {

    public static boolean isValid(String cnp) {
        // verifica validitate cnp

        String defaultCnp = "279146358279";
        int sum = 0;
        int k = 0;  // defaultCnp counter

        for (int i = 0; i < 12; i++) {
            sum += Integer.parseInt(String.valueOf(cnp.charAt(i))) * Integer.parseInt(String.valueOf(defaultCnp.charAt(i)));
        }

        int cifraControl = Integer.parseInt(String.valueOf(cnp.charAt(cnp.length() - 1)));

        boolean condition_1 = Pattern.matches("^[1256]\\d{12}$", cnp);

        boolean condition_2 =
                (sum % 11 == 10) ? (cifraControl == 1) : (cifraControl == sum % 11);

        return condition_1 && condition_2;
    }


    public static Persoana[] getPersoane(String in) throws IOException {
        // citeste persoanele intr-un vector

        BufferedReader br = new BufferedReader(new FileReader(in));
        Scanner scanner = new Scanner(System.in);
        Persoana[] persoane = new Persoana[100];

        String line;

        int k = 0;  // counter persoane

        System.out.println("\nEXCEPTI:");

        while ((line = br.readLine()) != null) {

            String[] date = line.split(" ");

            // verifica validitate cnp
            if (!isValid(date[2].trim())) {

                int valid = 0;
                System.out.println("[ ! ] CNP INVALID [ ! ] Nume: " + date[0].trim() + " " +date[1].trim() + ", CNP: " + date[2].trim());
                do {
                    System.out.print("Introduceti un CNP valid pentru : " + date[0].trim() + " " + date[1].trim() + ": ");
                    String cnp_citit = scanner.nextLine();
                    if (isValid(cnp_citit))
                        valid = 1;
                } while(valid == 0);
            }

            persoane[k] = new Persoana(date[0].trim() + " " + date[1].trim(), date[2].trim());

            k++;
        }

        br.close();

        // copiere in vector nou
        Persoana[] persoane_ = new Persoana[k];
        System.arraycopy(persoane, 0, persoane_, 0, k);

        return persoane_;
    }

    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);

        String in = "src\\ex_4\\in.txt";
        String out = "src\\ex_4\\out.txt";

        Persoana[] persoane = getPersoane(in);

        System.out.println("\nSUCCES:");

        for (Persoana p: persoane
             ) {
            System.out.println("Nume: " + p.getNume() + ", CNP: " + p.getCnp() + ", Varsta: " + p.getVarsta());
        }

        scanner.close();
    }
}
