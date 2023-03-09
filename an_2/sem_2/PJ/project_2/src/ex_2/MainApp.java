package ex_2;

import java.io.*;
import java.util.Scanner;

public class MainApp {

    // citire versuri (-> Vers[])
    public static Vers[] readLyrics(String in_file) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(in_file));

        // tablou de obiecte tip Vers
        Vers [] lyrics = new Vers[100];

        int k = 0;  // counter
        String line;

        // iterare fiecare linie din in_file
        while ((line = br.readLine()) != null) {

            // apelare constructor clasa Vers
            Vers verset = new Vers(line);

            // adaugare vers in tablou
            lyrics[k] = verset;

            // incrementare contor
            k++;
        }

        br.close();

        Vers[] lyrics_ = new Vers[k];
        System.arraycopy(lyrics, 0, lyrics_, 0, k);

        return lyrics_;
    }

    // procesare/scriere versuri
    public static void processLyrics(Vers[] lyrics, String out_file) throws IOException {

        BufferedWriter bw = new BufferedWriter(new FileWriter(out_file));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // citire sufix
        System.out.println("Introduceti sufix: ");
        String suffix = br.readLine();

        int k = 0;  // contor

        // iterare fiecare vers
        for (Vers vers: lyrics
             ) {
            // daca versul e blank, nu afisam numarul de cuvinte si litere
            if (vers.getLine().isBlank()){
                bw.write("\n");
                continue;
            }

            // verificare random
            String vers_ = vers.getLine();
            double random_n = Math.random();

            if (random_n < 0.1){
                vers_ = vers.getLine().toUpperCase();
            }


            // scriere vers procesat
            bw.write(vers_ + " || numar generat: " + String.format("%.2f", random_n) +  ", cuvinte: " + vers.getWordsNum() + ", vocale: " + vers.getVowelsNum());

            // verificare sufix vers
            if (vers.getLine().endsWith(suffix)){
                bw.append(" *");
            }

            bw.append("\n");
        }

        bw.close();
        br.close();
    }

    // main
    public static void main(String[] args) throws IOException {
        String in_file = "src\\ex_2\\cantec_in.txt";
        String out_file = "src\\ex_2\\cantec_out.txt";

        BufferedReader br = new BufferedReader(new FileReader(in_file));

        Vers[] lyrics = readLyrics(in_file);

        processLyrics(lyrics, out_file);

        br.close();

    }
}
