package org.create_start_stop_threads;

public class Ex_7 {
    public static void main(String[] args) throws InterruptedException {

        Runnable runnable = () -> {
            for (int i=0; i<5; i++) {
                sleep(1000);
                System.out.println(Thread.currentThread().getName() + " running");
            }
        };

        Thread thread = new Thread(runnable);
        thread.setDaemon(true);
        thread.start();

        thread.join(); // wai ting for the daemon thread to finish
    }

    public static void sleep(long millis) {
        try {
            Thread.sleep(millis);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }


}
