package org.create_start_stop_threads;

public class Ex_6 {
    public static void main(String[] args) throws InterruptedException {

        Runnable runnable = () -> {
            while (true) {
                sleep(1000);
                System.out.println(Thread.currentThread().getName() + " running");
            }
        };

        Thread thread = new Thread(runnable);
        thread.setDaemon(true); // daemon thread
        thread.start();

        sleep(3000);
        System.out.println("Main thread finished, killing all daemons :)");
    }

    public static void sleep(long millis) {
        try {
            Thread.sleep(millis);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }


}
