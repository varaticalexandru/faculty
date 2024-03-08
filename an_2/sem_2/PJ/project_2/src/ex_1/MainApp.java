package ex_1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class MainApp {
    
    static public void printArr(String[] arr, int n) {
        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        String in_file = "src\\ex_1\\judete_in.txt";
        BufferedReader br = new BufferedReader(new FileReader(in_file));

        String line;
        String[] judete = new String [100];


        int k = 0;  // counter

        while ((line = br.readLine()) != null) {
            judete[k] = line;
            k++;
        }

        // copiere tablou in tablou nou (k elemente)
        String[] judete_ = new String [k];
        System.arraycopy(judete, 0, judete_, 0, k);

        // sortare tablou
        Arrays.sort(judete_, 0, k);

        // afisare tablou sortat
        System.out.println("\nTablou sortat de judete:\n");
        printArr(judete_, k);

        // cautare judet
        System.out.println("\nIntroduceti judetul cautat: ");
        String judet_cautat = scanner.nextLine();
        
        Integer key = Arrays.binarySearch(judete_, judet_cautat);
        System.out.println("\nCheia/Indexul judetului cautat: " + key);

        br.close();
        scanner.close();
    }
}
