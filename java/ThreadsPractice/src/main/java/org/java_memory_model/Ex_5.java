package org.java_memory_model;

public class Ex_5 {
    public static void main(String[] args) throws InterruptedException {

        Object object = new Object();

        Runnable r1 = new MyRunnable4(object);
        Runnable r2 = new MyRunnable4(object);

        Thread t1 = Thread.ofPlatform().start(r1);
        Thread t2 = Thread.ofPlatform().start(r2);

        t1.join();
        t2.join();

    }
}
