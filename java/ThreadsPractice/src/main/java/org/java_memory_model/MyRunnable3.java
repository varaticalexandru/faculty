package org.java_memory_model;

public class MyRunnable3 implements Runnable {
    private int count = 0;

    Object object = new Object();
    @Override
    public void run() {

        for (int i=0; i<1_000_000; i++)
            this.count++;

        System.out.println(Thread.currentThread().getName() + ": " + this.count);
        System.out.println(Thread.currentThread().getName() + ": " + object);
    }
}
