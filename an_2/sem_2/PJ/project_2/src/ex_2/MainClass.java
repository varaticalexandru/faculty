package ex_2;

import java.io.*;
import java.util.Scanner;

public class MainClass {

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

        int k = 0;  // contor

        // iterare fiecare vers si scriem versul procesat in out_file
        for (Vers vers: lyrics
             ) {
            bw.write(vers.getLine() + " : " + vers.getWordsNum() + " : " + vers.getVowelsNum());
        }



        bw.close();
    }

    // main
    public static void main(String[] args) throws IOException {
        String in_file = "src\\ex_2\\cantec_in.txt";
        String out_file = "src\\ex_2\\cantec_out.txt";

        Scanner scanner = new Scanner(System.in);
        BufferedReader br = new BufferedReader(new FileReader(in_file));

        Vers[] lyrics = readLyrics(in_file);



        br.close();

    }
}
