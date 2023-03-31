package ex_1;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule;

import java.io.File;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Angajat {

    // members

    private String nume;
    private String post;
    private LocalDate data_angajarii;
    private Float salariul;

    // getters & setters
    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getPost() {
        return post;
    }

    public void setPost(String post) {
        this.post = post;
    }

    public LocalDate getData_angajarii() {
        return data_angajarii;
    }

    public void setData_angajarii(LocalDate data_angajarii) {
        this.data_angajarii = data_angajarii;
    }

    public Float getSalariul() {
        return salariul;
    }

    public void setSalariul(Float salariul) {
        this.salariul = salariul;
    }

    // constructors
    public Angajat(String nume, String post, LocalDate data_angajarii, Float salariul) {
        this.nume = nume;
        this.post = post;
        this.data_angajarii = data_angajarii;
        this.salariul = salariul;
    }

    public Angajat() {}

    // methods

    @Override
    public String toString() {
        return
            this.nume + ", " +
            this.post + ", " +
            this.data_angajarii.format(DateTimeFormatter.ofPattern("dd.MM.yyyy")) + ", " +
            String.format("%.2f", this.salariul) +
            "\n";

    }

    // deserializarea lista de angajati din .json
    public static List<Angajat> deserialize(String pathname) {

        List<Angajat> angajati = new ArrayList<Angajat>();

        try {
            ObjectMapper mapper = new ObjectMapper();
            mapper.registerModule(new JavaTimeModule());
            File f = new File(pathname);
            angajati = mapper
                    .readValue(f, new TypeReference<List<Angajat>>() {});
        }
        catch(Exception e) {
            e.printStackTrace();
        }

        return angajati;
    }

    // serializarea listei de angajati in .json
    public static void serialize(String pathname, List<Angajat> angajati) {

        try {
            ObjectMapper mapper = new ObjectMapper();
            mapper.registerModule(new JavaTimeModule());
            mapper.disable(SerializationFeature.WRITE_DATES_AS_TIMESTAMPS);
            File f = new File(pathname);
            mapper
                    .writeValue(f, angajati);
        }
        catch(Exception e) {
            e.printStackTrace();
        }


    }

    // afisarea listei de angajati
    public static void afisareListaAngajati(List<Angajat> angajati) {
        angajati
                .stream()
                .forEach(System.out::println);
    }

    // afisarea angajatilor care au salariul peste 2500 RON
    public static void afisareAngajatiFiltruSalariu(List<Angajat> angajati) {
        angajati
                .stream()
                .filter( (a) -> a.getSalariul() > 2500)
                .forEach(System.out::println);
    }

    // lista cu angajatii din luna aprilie a anului trecut, care au functie de conducere
    public static List<Angajat> getListaAngajatiConducere(List<Angajat> angajati) {

        LocalDate now = LocalDate.now();
        int last_year = now.getYear() - 1;
        LocalDate target = LocalDate.of(last_year, 4, 1);

         return angajati
                .stream()
                .filter( (a) -> a.getData_angajarii().compareTo(target) >= 0 )
                .filter( (a) -> a.getPost().contains("Sef") || a.getPost().contains("Director"))
                .collect(Collectors.toList());

    }

}
