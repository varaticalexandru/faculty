package org.thread_local;

public class InheritableThreadLocalEx {

    public static void main(String[] args) {

        ThreadLocal<String> threadLocal = new ThreadLocal<>();
        InheritableThreadLocal inheritableThreadLocal = new InheritableThreadLocal();

        Thread thread = new Thread(() -> {
            threadLocal.set("value-1");
            inheritableThreadLocal.set("value-2");

            System.out.println("---- Thread 1 ----");
            System.out.println("value from ThreadLocal: " + threadLocal.get());
            System.out.println("value from InehritableThreadLocal: " + inheritableThreadLocal.get() + "\n");

            Thread childThread = new Thread(() -> {
                System.out.println("---- Thread 1 child ----");
                System.out.println("value from ThreadLocal: " + threadLocal.get());
                System.out.println("value from InehritableThreadLocal: " + inheritableThreadLocal.get() + "\n");
            });
            childThread.start();
        });

        thread.start();


        // thread2 does not inherit any values set by thread1
        Thread thread2 = new Thread(() -> {
            try {
                Thread.sleep(3000);
            }
            catch (InterruptedException ex) {
                ex.printStackTrace();
            }

            System.out.println("---- Thread 2 ----");
            System.out.println("value from ThreadLocal: " + threadLocal.get());
            System.out.println("value from InehritableThreadLocal: " + inheritableThreadLocal.get());
        });

        thread2.start();



    }



}
