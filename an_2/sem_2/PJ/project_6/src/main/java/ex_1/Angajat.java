package ex_1;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.SerializationFeature;
import com.fasterxml.jackson.datatype.jsr310.JavaTimeModule;

import java.io.File;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.DoubleSummaryStatistics;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.stream.Collectors;

public class Angajat {

    // members

    private String nume;
    private String post;
    private LocalDate data_angajarii;
    private Float salariul;



    // constructors
    public Angajat(String nume, String post, LocalDate data_angajarii, Float salariul) {
        this.nume = nume;
        this.post = post;
        this.data_angajarii = data_angajarii;
        this.salariul = salariul;
    }

    public Angajat() {}



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

    // deserializeaza lista de angajati din .json
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

    // serializeaza listei de angajati in .json
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

    // afiseaza lista de angajati
    public static void afisareListaAngajati(List<Angajat> angajati) {
        angajati
            .stream()
            .forEach(System.out::println);
    }

    // afiseaza angajatii cu salariu > 2500 RON
    public static void afisareAngajatiFiltruSalariu(List<Angajat> angajati) {
        angajati
                .stream()
                .filter( (a) -> a.getSalariul() > 2500)
                .forEach(System.out::println);
    }

    // lista cu angajatii din luna aprilie a anului trecut, care au functie de conducere
    public static List<Angajat> getAngajatiConducere(List<Angajat> angajati) {

        LocalDate now = LocalDate.now();
        int last_year = now.getYear() - 1;
        LocalDate target = LocalDate.of(last_year, 4, 1);

         return angajati
                .stream()
                .filter( (a) -> a.getData_angajarii().isAfter(target) )
                .filter( (a) -> a.getPost().contains("Sef") || a.getPost().contains("Director"))
                .collect(Collectors.toList());
    }

    // lista cu angajati care nu au functie de conducare, in ordine descrescatoare a salariilor
    public static List<Angajat> getAngajatiNonConducere(List<Angajat> angajati) {

        return angajati
                .stream()
                .filter( (a) -> !a.getPost().contains("Sef") && !a.getPost().contains("Director") )
                .sorted( (a, b) -> b.getSalariul().compareTo(a.getSalariul()) )
                .collect(Collectors.toList());
    }

    // lista de String-uri cu numele angajatilor scrise cu majuscula
    public static List<String> getNumeAngajati(List<Angajat> angajati) {
        return angajati
                .stream()
                .map( (a) -> a.getNume().toUpperCase() )
                .sorted( (a, b) -> a.compareTo(b) )
                .collect(Collectors.toList());
    }

    // afisarea salariilor < 3000
    public static void afisareSalariiMici3000(List<Angajat> angajati) {
         angajati
                 .stream()
                 .map(a -> a.getSalariul())
                 .filter(s -> s < 3000)
                 .forEach(System.out::println);
    }

    // afisarea datelor primului angajat al firmei
    public static void afisarePrimAngajat(List<Angajat> angajati) {
        try {
            Angajat angajat_prim = angajati
                    .stream()
                    .min( (a, b) -> a.getData_angajarii().compareTo(b.getData_angajarii()))
                    .orElseThrow();

            System.out.println(angajat_prim);
        }
        catch (NoSuchElementException e) {
            e.printStackTrace();
            System.out.println("Eroare ! Nu exista un prim angajat !");
        }


//        angajati
//                .stream()
//                .min( (a, b) -> a.getData_angajarii().compareTo(b.getData_angajarii()))
//                .ifPresentOrElse(System.out::println, () -> System.out.println("Eroare ! Nu exista un prim angajat !"));

    }

    // afisare stats referitoare la salariul angajatilor (min, max, avg)
    public static void statsAngajati(List<Angajat> angajati) {

        DoubleSummaryStatistics stats = angajati
                .stream()
                .collect(Collectors.summarizingDouble(Angajat::getSalariul));

        System.out.println("Salariul minim: " + stats.getMin());
        System.out.println("Salariul maxim: " + stats.getMax());
        System.out.println("Salariul mediu: " + String.format("%.2f", stats.getAverage()));
    }

    // afisare daca exista cel putin un Ion
    public static void checkIon(List<Angajat> angajati) {


        angajati
                .stream()
                .filter(s -> s.getNume().contains("Ion"))
                .findAny()
                .ifPresentOrElse(System.out::println, () -> System.out.println("Nu exista nici un Ion !"));
    }


    // afisarea nr. de persoana care s-au angajat in vara anului trecut
    public static void afisareNrPersAngajataVaraTrecuta(List<Angajat> angajati) {

        LocalDate low_boundary = LocalDate.of(LocalDate.now().getYear()-1, 6, 1);
        LocalDate high_boundary = LocalDate.of(LocalDate.now().getYear()-1, 8, 31);


        /*
        Integer nr_angajati = (int) angajati
                .stream()
                .filter( (a) -> a.getData_angajarii().compareTo(low_boundary) >= 0 )
                .filter( (a) -> a.getData_angajarii().compareTo(high_boundary) <= 0)
                .count();
         */

       Integer nr_angajati = (int) angajati
               .stream()
               .filter( (a) -> a.getData_angajarii().isAfter(low_boundary))
               .filter( (a) -> a.getData_angajarii().isBefore(high_boundary))
               .count()
       ;



        System.out.println("Nr. persoane care s-au angajat in vara anului trecut: " + nr_angajati);
    }
}
