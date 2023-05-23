package org.example.ex_2;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.AbstractApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

import javax.naming.Context;

public class MainApp {

    public static void main(String[] args) {

        //  -- injectarea valorilor prin metadate de configurare din .xml --

//        AbstractApplicationContext context = new ClassPathXmlApplicationContext("beans_lab1.xml");

//        // a
//        Vehicul autoturism_1 = (Vehicul) context.getBean("autoturism_1");
//        System.out.println(autoturism_1);
//
//        // b
//        Vehicul autoturism_2 = (Vehicul) context.getBean("autoturism_2");
//        System.out.println(autoturism_2);

//        // c
//        Vehicul motocicleta_1 = (Motocicleta) context.getBean("motocicleta_1");
//        System.out.println(motocicleta_1);
//        context.registerShutdownHook();
//        context.close();



        // -- injectarea valorilor prin adnotatii --

//        ApplicationContext context = new ClassPathXmlApplicationContext("beans_lab2.xml");
//
//        Vehicul autoturism_1 = (Vehicul) context.getBean("autoturism");
//        System.out.println(autoturism_1);
//
//        Vehicul autoturism_2 = (Vehicul) context.getBean("autoturism");


//        ApplicationContext context = new ClassPathXmlApplicationContext("beans_lab3.xml");
//        Vehicul autoturism_2 = (Vehicul) context.getBean("autoturism");
//        System.out.println(autoturism_2);



//        AbstractApplicationContext context = new ClassPathXmlApplicationContext("beans_lab4.xml");
//        Vehicul motocicleta = (Motocicleta) context.getBean("motocicleta");
//        System.out.println(motocicleta);
//
//
//        context.registerShutdownHook();
//        context.close();

        AbstractApplicationContext context = new ClassPathXmlApplicationContext("beans_lab5.xml");
        Vehicul tir = (Vehicul) context.getBean("tir");
        System.out.println(tir);

        context.registerShutdownHook();
        context.close();



    }
}
