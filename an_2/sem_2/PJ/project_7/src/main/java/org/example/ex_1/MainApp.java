package org.example.ex_1;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;

public class MainApp {

    // deserializare carti in HashMap
    public static Map<Integer, Carte> deserializeBooks(String filepath) throws IOException {

        File f = new File(filepath);
        ObjectMapper mapper = new ObjectMapper();

         return mapper
                .readValue(f, new TypeReference<HashMap<Integer, Carte>>() {});
    }

    // afisare HashMap (key, value)
    public static void displayMap(Map<Integer, Carte> carti) {

        System.out.println();

//        for (Map.Entry<Integer, Carte> entry: carti.entrySet()) {
//            System.out.println("Key: " + entry.getKey() + "\nValue: " + entry.getValue() + "\n");
//        }

        carti
                .entrySet()
                .stream()
                .forEach((entry) -> System.out.println(entry.getKey() + ": " + entry.getValue()));
    }

    // stergere carte din Map (dupa key)
    public static void deleteBookFromMap(Map<Integer, Carte> carti, int del_id) {
        carti.remove(del_id);
    }

    // adaugare carte la Map
    public static void addBookToMap(Map<Integer, Carte> carti, int id, Carte carte) {

        carti.putIfAbsent(id, carte);
    }

    // serializare in .json
    public static void serializeBooks(String filepath, Map<Integer, Carte> carti) throws IOException {

        File f = new File(filepath);
        ObjectMapper mapper = new ObjectMapper();
        mapper.writeValue(f, carti);
    }

    // extragere set carti dupa autor
    public static Set<Carte> getBooksByAuthor(Map<Integer, Carte> carti, String author) {

         return carti
                 .values()
                .stream()
                .filter(carte -> carte.autorul().equals(author))
                .collect(Collectors.toSet());
    }

    // afisare set carti sortate dupa titlu
    public static void displayBooksByTitle(Set<Carte> carti) {
        carti
                .stream()
                .sorted((c1, c2) -> c1.titlul().compareTo(c2.titlul()))
                .forEach(System.out::println);
    }

    public static void displayOldestBook(Map<Integer, Carte> carti) {

        carti
                .values()
                .stream()
                .min((c1, c2) -> c1.anul() - c2.anul())
                .ifPresent(System.out::println);
    }


    public static void main(String[] args) throws IOException {

        String filepath = "src/main/resources/carti.json";
        Map<Integer, Carte> carti = new HashMap<Integer, Carte>();
        Scanner scanner = new Scanner(System.in);

        carti = deserializeBooks(filepath);


        // 1) afisare colectie (key, value)
        displayMap(carti);

        // 2) stergere carte din colectie
        System.out.print("\nIntroduceti cheia cartii sterse: ");
        int del_id = scanner.nextInt();
        scanner.nextLine(); // consuma \n

        deleteBookFromMap(carti, del_id);

        // 3) adaugare carte la colectie
        System.out.println("\nIntroduceti datele unei carti noi: ");
        System.out.print("ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Titlul: ");
        String titlu = scanner.nextLine();
        System.out.print("Autorul: ");
        String autor = scanner.nextLine();
        System.out.print("Anul: ");
        int an = scanner.nextInt();

        Carte carte = new Carte(titlu, autor, an);
        addBookToMap(carti, id, carte);

        displayMap(carti);

        // 4) serializare in .json
        serializeBooks(filepath, carti);

        // 5) extragere set carti ale autorului Yuval Noah Harari
        Set<Carte> cartiHarari = getBooksByAuthor(carti, "Yuval Noah Harari");

        System.out.println("\nCartile lui Yuval Noah Harari: ");
        cartiHarari
                .forEach(System.out::println);

        // 6) afisare set carti sortate dupa titlu
        System.out.println("\nCartile sortate dupa titlu: ");
        displayBooksByTitle(cartiHarari);

        // 7) afisare date cea mai veche carte
        System.out.println("\nDatele celei mai vechi carti: ");
        displayOldestBook(carti);



        scanner.close();
    }
}
