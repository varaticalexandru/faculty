package org.java_memory_model;

public class MyRunnable2 implements Runnable {
    private int count = 0;

    @Override
    public void run() {

        Object object = new Object();

        for (int i=0; i<1_000_000; i++)
            this.count++;

        System.out.println(Thread.currentThread().getName() + ": " + this.count);
        System.out.println(Thread.currentThread().getName() + ": " + object);
    }
}