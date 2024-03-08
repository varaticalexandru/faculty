package org.java_memory_model;

public class MyRunnable_ implements Runnable {

    private int count = 0;

    @Override
    public void run() {
        for (int i=0; i<1_000_000; i++)
            synchronized (this) {
                this.count++;
            }

        System.out.println(Thread.currentThread().getName() + ": " + this.count);
    }
}
