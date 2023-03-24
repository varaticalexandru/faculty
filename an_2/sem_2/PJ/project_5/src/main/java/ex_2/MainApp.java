package ex_2;

import java.util.ArrayList;
import java.util.List;
import java.io.IOException;
import java.io.File;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import ex_0.Persoana;

public class MainApp {

    // serializeaza JSON
    public static void scriere(List<PerecheNumere> perechi)
    {
        try {
            ObjectMapper mapper = new ObjectMapper();
            File file = new File("src\\main\\resources\\perechi.json");
            mapper.writeValue(file, perechi);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    // deserializeaza JSON
    public static List<PerecheNumere> citire(String in_file)
    {
        try {
            File file = new File(in_file);
            ObjectMapper mapper = new ObjectMapper();
            List<PerecheNumere> perechi = mapper
                    .readValue(file, new TypeReference<List<PerecheNumere>>() {});

            return perechi;
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }


    public static void main(String[] args) {

        List<PerecheNumere> perechi = new ArrayList<PerecheNumere>();  // lista perechi

        // adaugare perechi in lista
        perechi.add(new PerecheNumere(3, 5));
        perechi.add(new PerecheNumere(0, 2));
        perechi.add(new PerecheNumere(5, 6));
        perechi.add(new PerecheNumere(1, 2));
        perechi.add(new PerecheNumere(8, 7));


        MainApp.scriere(perechi);

        List<PerecheNumere> perechi_2 = new ArrayList<PerecheNumere>();
        perechi_2 = MainApp.citire("src\\main\\resources\\perechi.json");

        for (var pereche: perechi_2
             ) {
            System.out.println(pereche);
        }


    }
}
