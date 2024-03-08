package org.synchronized_keyword;

public class StaticSynchronizedExchange {

    protected static Object object = null;

    public static synchronized void setObject(Object o) {
        object = o;
    }

    public static void setObj(Object o) {
        synchronized(StaticSynchronizedExchange.class) {
            object = o;
        }
    }
}
