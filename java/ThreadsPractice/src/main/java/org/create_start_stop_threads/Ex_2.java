package org.create_start_stop_threads;

public class Ex_2 {
    public static void main(String[] args) {
        Thread thread_1 = new Thread(print("Hello there"));
        Thread thread_2 = new Thread(() -> System.out.println("Hello there" + " from " + Thread.currentThread().getName()));
        Thread thread_3 = new MyThread();
        Thread thread_4 = new Thread(new MyRunnable());

        thread_1.start();
        thread_2.start();
        thread_3.start();
        thread_4.start();
    }

    private static Runnable print(String message) {
        return () -> {
            System.out.println(message + " from " + Thread.currentThread().getName());
        };
    }

    public static class MyThread extends Thread {

        @Override
        public void run() {
            System.out.println("Hello there" + " from " + Thread.currentThread().getName());
        }
    }

    public static class MyRunnable implements Runnable {

        @Override
        public void run() {
            System.out.println("Hello there" + " from " + Thread.currentThread().getName());
        }
    }

}
