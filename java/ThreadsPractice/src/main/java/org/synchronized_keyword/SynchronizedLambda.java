package org.synchronized_keyword;

import java.util.Objects;
import java.util.function.Consumer;

public class SynchronizedLambda {

    private static Object object = null;

    public synchronized static void setObject(Object o) {
        object = o;
    }

    public static void consumeObject(Consumer consumer) {
        consumer.accept(object);
    }


    public static void main(String[] args) {

        consumeObject(obj -> {
            synchronized (SynchronizedLambda.class) {
                System.out.println(obj);
            }
        });

    }
}
