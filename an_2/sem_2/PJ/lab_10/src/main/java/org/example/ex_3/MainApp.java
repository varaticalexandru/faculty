package org.example.ex_3;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import java.util.List;
import java.util.Scanner;

public class MainApp {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        AbstractApplicationContext context = new ClassPathXmlApplicationContext("beans_jdbc.xml");

        MasinaController masinaController = (MasinaController) context.getBean("masinaController");

        // a) adaugarea unei masini
        // masinaController.insert("TM006", "Dacia", 2002, "galben", 25000);

        // b) stergerea unei masini
        // masinaController.delete("TM007");

        // c) cautarea unei masini
//        Masina masina = masinaController.getMasina("TM002");
//        System.out.println(masina);

        // d) afisarea tuturor masinilor
//        List<Masina> masini = masinaController.getListaMasini();
//        for (Masina m: masini
//             ) {
//            System.out.println(m);
//        }

        // e) afisarea nr. de masini care au o anumita marca
//        System.out.print("Introduceti marca: ");
//        String marca = scanner.nextLine();
//
//        System.out.println(masinaController.getNrMasiniMarca(marca));

        // f) afisarea masinilor care au < 100.000 km
//        List<Masina> masini = masinaController.getListaMasiniNrKilometri();
//
//        for (Masina m: masini
//             ) {
//            System.out.println(m);
//        }

        // g) afisarea masinilor mai vechi de 5 ani
        List<Masina> masini = masinaController.getListaMasiniVarsta();
        for (Masina m: masini
             ) {
            System.out.println(m);
        }
    }
}
