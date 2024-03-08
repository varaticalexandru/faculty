package org.create_start_stop_threads;

public class Ex_3 {
    public static void main(String[] args) {
        Runnable runnable = () -> {
            System.out.println(Thread.currentThread().getName() + " running");
        };

        new Thread(runnable, "Thread-1").start();
        new Thread(runnable, "Thread-2").start();
    }

}
