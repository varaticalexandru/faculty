package org.java_memory_model;

import java.util.concurrent.atomic.AtomicInteger;

public class MyRunnable__ implements Runnable {

    private final AtomicInteger count = new AtomicInteger(0);

    @Override
    public void run() {
        for (int i=0; i<1_000_000; i++)
            count.addAndGet(1);


        System.out.println(Thread.currentThread().getName() + ": " + this.count);
    }
}
