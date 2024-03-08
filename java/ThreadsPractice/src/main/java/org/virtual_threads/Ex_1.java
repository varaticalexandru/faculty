package org.virtual_threads;

public class Ex_1 {
    public static void main(String[] args) throws InterruptedException {

        Runnable runnable = () -> {
            for (int i=0; i<10; i++) {
                System.out.println(i);
            }
        };

        Thread t1 = Thread.ofVirtual().unstarted(runnable);
//        Thread t2 = Thread.ofVirtual().start(runnable);
        t1.start();
        t1.join();
    }
}
