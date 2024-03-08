package org.java_memory_model;

public class Ex_3 {
    public static void main(String[] args) throws InterruptedException {

        Runnable r = new MyRunnable2();

        Thread t1 = Thread.ofPlatform().start(r);
        Thread t2 = Thread.ofPlatform().start(r);

        t1.join();
        t2.join();

    }
}
