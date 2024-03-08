package org.synchronized_keyword;

public class Main {

    public static void main(String[] args) {

        SynchronizedExchanger synchronizedExchanger = new SynchronizedExchanger();

        Thread thread1 = new Thread(() -> {
            for (int i=0; i<1000; i++)
                synchronizedExchanger.setObject("" + i);
        });

        Thread thread2 = new Thread(() -> {
            for (int i=0; i<1000; i++)
                System.out.println(synchronizedExchanger.getObject());
        });

        thread1.start();
        thread2.start();
    }
}


