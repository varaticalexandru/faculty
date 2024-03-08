package org.create_start_stop_threads;

public class Ex_4 {
    public static void main(String[] args) {

        Runnable runnable = () -> {
            System.out.println(Thread.currentThread().getName() + " running");
            System.out.println("Sleeping for 3 seconds ...");

            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            System.out.println(Thread.currentThread().getName() + " finished");

        };

        new Thread(runnable, "Thread-1").start();
    }

}
