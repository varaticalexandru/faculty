package ex_1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class MainApp {

    public static void getParabole(String in) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(in));
        List<Parabola> parabole = new ArrayList<Parabola>();

        String line;

        while ((line = br.readLine()) != null) {
            String[] coeficenti = line.split(" ");

            Integer a =  Integer.parseInt(coeficenti[0].trim());
            Integer b = Integer.parseInt(coeficenti[1].trim());
            Integer c = Integer.parseInt(coeficenti[2].trim());

            System.out.println(a + " " + b + " " + c);

        }



        br.close();

        //return parabole;
    }
    public static void main(String[] args) throws IOException {

        //List<Parabola> parabole = ;
        String in = "src\\ex_1\\in.txt";

        getParabole(in);
    }
}
