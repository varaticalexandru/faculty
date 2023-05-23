package org.example.ex_0;

import org.springframework.beans.factory.BeanFactory;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class MainApp {
    public static void main(String[] args) {

        BeanFactory factory = new ClassPathXmlApplicationContext("beans01.xml");

//        Dreptunghi d_1 = (Dreptunghi)factory.getBean("dreptunghi_1");
//        d_1.aria();

        Dreptunghi d_2 = (Dreptunghi)factory.getBean("dreptunghi_2");
        d_2.aria();


    }
}
