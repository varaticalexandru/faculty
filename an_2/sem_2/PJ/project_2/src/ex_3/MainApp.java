package ex_3;

import java.io.*;

public class MainApp {
    public static void main(String[] args) throws IOException {

        BufferedReader in = new BufferedReader(new FileReader("src\\ex_3\\in.txt"));
        BufferedWriter out = new BufferedWriter(new FileWriter("src\\ex_3\\out.txt"));

        // citire
        StringBuilder sir = new StringBuilder(in.readLine());
        String subsir = in.readLine();
        Integer poz_inserare = Integer.parseInt(in.readLine());
        Integer poz_stergere = Integer.parseInt(in.readLine());
        Integer lungime_stergere = Integer.parseInt(in.readLine());

        // inserare subsir in sir la pozitie
        sir.insert(poz_inserare, subsir);

        // stergere subsir (poz_stergere, lungime_stergere)
        sir.delete(poz_stergere, poz_stergere + lungime_stergere);

        // scriere sir rezultat
        out.write(String.valueOf(sir));

        in.close();
        out.close();
    }
}
