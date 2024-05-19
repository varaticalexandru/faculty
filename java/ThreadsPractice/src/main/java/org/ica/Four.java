package org.ica;

import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public class Four {

    public static void main(String[] args) {
        List list = Arrays.asList(
                "1", "2", "3"
        );

        Iterator i = list.iterator();

        while (i.hasNext())
            System.out.print(i.next());
    }
}
