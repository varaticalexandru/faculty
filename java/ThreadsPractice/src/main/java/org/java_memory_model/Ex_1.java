package org.java_memory_model;

public class Ex_1 {
    public static void main(String[] args) throws InterruptedException {

        Runnable r1 = new MyRunnable();
        Runnable r2 = new MyRunnable();

        Thread t1 = Thread.ofPlatform().start(r1);
        Thread t2 = Thread.ofPlatform().start(r2);

        t1.join();
        t2.join();

    }
}
