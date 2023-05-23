package org.example.ex_1;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {

    public static void main(String[] args) {

        ApplicationContext context = new ClassPathXmlApplicationContext("beans02.xml");

//        Persoana p = (Persoana)context.getBean("persoana");

        Persoana p = (Persoana)context.getBean("persoana2");

        System.out.println(p);
    }
}
