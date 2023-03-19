package ex_1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MainApp {

    public static List <Parabola> getParabole(String in) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader(in));
        List <Parabola> parabole = new ArrayList <Parabola> ();

        String line;

        while ((line = br.readLine()) != null) {

            String[] coeficenti = line.split(" ");

            int a = Integer.parseInt(coeficenti[0].trim());
            int b = Integer.parseInt(coeficenti[1].trim());
            int c = Integer.parseInt(coeficenti[2].trim());

            Parabola p = new Parabola(a, b, c);

            parabole.add(p);
        }

        br.close();
        return parabole;
    }
    public static void main(String[] args) throws IOException {

        //List<Parabola> parabole = ;
        String in = "src\\ex_1\\in.txt";

        // citire
        List <Parabola> parabole = getParabole(in);

        // afisare
        System.out.println("\nFunctiile parabolelor si varfurile acestora:\n");
        for (Parabola p: parabole
             ) {
            System.out.println(p.toString()+" "+"| Varf: "+p.getVarf());
        }

        // generare 2 indecsi aleatori pentru lista de parabole
        Random rnd = new Random();

        int max = parabole.size();

        int idx_1  = rnd.nextInt(max);
        int idx_2  = rnd.nextInt(max);

        Parabola p1 = parabole.get(idx_1);
        Parabola p2 = parabole.get(idx_2);

        // afisare mijloc segment ce uneste varfurile a 2 parabole cu indecsii generati
        System.out.println("\nPentru parabolele:");
        System.out.println(p1.toString()+"| Varf: "+p1.getVarf());
        System.out.println(p2.toString()+"| Varf: "+p2.getVarf());

        System.out.println("Mijlocul segmentului ce uneste varfurile: "+p1.getMijloc(p2));
        System.out.println("Distanta dintre varfuri: "+Parabola.getDistanta(p1, p2));
    }
}
