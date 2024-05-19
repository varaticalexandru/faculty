package org.ica;

import java.util.ArrayList;
import java.util.List;

public class Three {

    public static void main(String[] args) {

        List list = new ArrayList();

        list.add("tone");
        list.add("two");
        list.add(7);

        for (Object o: list)
            System.out.println(o);

    }
}
