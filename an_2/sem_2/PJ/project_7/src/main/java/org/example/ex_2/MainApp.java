package org.example.ex_2;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;

import javax.lang.model.type.ReferenceType;
import java.io.File;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class MainApp {

    // serializare HashSet in .json
    public static void serialize(String filename, Set<InstrumentMuzical> instrumente) throws IOException {

        File f = new File(filename);
        ObjectMapper mapper = new ObjectMapper();

        mapper.activateDefaultTyping(mapper.getPolymorphicTypeValidator());

        mapper
                .writeValue(f, instrumente);
    }

    // deserializare HashSet din .json
    public static Set<InstrumentMuzical> deserialize(String filename) throws IOException {

        File f = new File(filename);
        ObjectMapper mapper = new ObjectMapper();

        Set<InstrumentMuzical> instrumente =  mapper
                .readValue(f, new TypeReference<HashSet<InstrumentMuzical>>() {});

        // 4) afisare implementare interfata Set
        System.out.println("\nImplementare interfata Set: " + instrumente.getClass());

        return instrumente;
    }

    // afisare HashSet instrumente
    public static void displaySet(Set<InstrumentMuzical> instrumente) {

        System.out.println("\nInstrumente:");
        instrumente
                .forEach(i -> System.out.println(i));
    }

    // verifica daca Set admite duplicate
    public static void checkDuplicate(Set<InstrumentMuzical> instrumente, InstrumentMuzical i) {

        boolean res = instrumente.add(new Chitara("Fender", 999.99f, TipChitara.ELECTRICA, 6));

        if (!res) {
            System.out.println("\nA fost introdus un duplicat !");
        }
        else {
            System.out.println("\nNu a fost introdus un duplicat !");
        }
    }

    // stergere instrumente pret > 3000 RON
    public static void removeInstrumente(Set<InstrumentMuzical> instrumente) {

        boolean res = instrumente
                .removeIf((i) -> i.getPret() > 3000);

        System.out.println("\nRezultat stergere: " + res);
    }

    // afisarea date chitare
    public static void displayGuitars(Set<InstrumentMuzical> instrumente) {

        System.out.println("\nChitare:");

        instrumente
                .stream()
                .filter(i -> i instanceof Chitara)
                .forEach(System.out::println);
    }

    // afisare date tobe
    public static void displayDrumSets(Set<InstrumentMuzical> instrumente) {

        System.out.println("\nTobe:");

        instrumente
                .stream()
                .filter(i -> i.getClass() == SetTobe.class)
                .forEach(System.out::println);
    }

    // datele chitarii cu cele mai multe corzi
    public static void displayMaxStringsGuitar(Set<InstrumentMuzical> instrumente) {

        System.out.println("\nChitara cu cele mai multe corzi: ");

        instrumente
                .stream()
                .filter(i -> i.getClass() == Chitara.class)
                .max( (c1, c2) -> ((Chitara) c1).getNr_corzi() - ((Chitara) c2).getNr_corzi())
                .ifPresentOrElse(
                        System.out::println,
                        () -> System.out.println("Eroare ! Nici o chitara disponibila/valida !")
        );
    }

    // datele tobelor acustice, ordonat dupa nr. de tobe
    public static void displayOrderedAcousticGuitars(Set<InstrumentMuzical> instrumente) {

        System.out.println("\nTobele acustice, ordonate dupa nr. de tobe: ");

        instrumente
                .stream()
                .filter(i -> i instanceof SetTobe)
                .filter(t -> ((SetTobe) t).getTip_tobe() == TipTobe.ACUSTICE)
                .sorted( (t1, t2) -> ((SetTobe) t1).getNr_tobe() - ((SetTobe) t2).getNr_tobe())
                .forEach(System.out::println);
    }

    public static void main(String[] args) throws IOException {

        String filename = "src\\main\\resources\\instrumente.json";
        Scanner scanner = new Scanner(System.in);

        Set<InstrumentMuzical> instrumente = new HashSet<InstrumentMuzical>();

        // 1) creeare colectie

//        Chitara chitara_0 = new Chitara("Fender", 999.99f, TipChitara.ELECTRICA, 6);
//        Chitara chitara_1 = new Chitara("Gibson", 1599, TipChitara.ACUSTICA, 6);
//        Chitara chitara_2 = new Chitara("Yamaha", 349.99f, TipChitara.CLASICA, 6);
//
//        SetTobe setTobe_0 = new SetTobe("Pearl", 1299, TipTobe.ELECTRONICE, 5, 3);
//        SetTobe setTobe_1 = new SetTobe("Tama", 1499, TipTobe.ACUSTICE, 7, 4);
//        SetTobe setTobe_2 = new SetTobe("Ludwig", 1799, TipTobe.ELECTRONICE, 6, 2);
//
//        instrumente.add(chitara_0);
//        instrumente.add(chitara_1);
//        instrumente.add(chitara_2);
//
//        instrumente.add(setTobe_0);
//        instrumente.add(setTobe_1);
//        instrumente.add(setTobe_2);

        // 2) serializare in .json

//        serialize(filename, instrumente);

        // 3) deserializare
        instrumente = deserialize(filename);

        displaySet(instrumente);

        // 5) verifica daca Set admite duplicate
        checkDuplicate(instrumente, new Chitara("Fender", 999.99f, TipChitara.ELECTRICA, 6));

        // 6) stergere instrumente pret > 3000 RON
        removeInstrumente(instrumente);

        displaySet(instrumente);

        // 7) afisare date chitari
        displayGuitars(instrumente);

        // 8) afisare date tobe
        displayDrumSets(instrumente);

        // 9) datele chitarii cu cele mai multe corzi
        displayMaxStringsGuitar(instrumente);

        // 10) datele tobelor acustice, ordonat dupa nr. de tobe
        displayOrderedAcousticGuitars(instrumente);

    }
}
