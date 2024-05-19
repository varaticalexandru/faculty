package org.volatile_;

public class Main {

    private static volatile int count = 0;


    public static void main(String[] args) throws InterruptedException {


        Runnable task = () -> {
            for (int i = 0; i < 20; i++) {
                if (count == 10)
                    return;

                count++;
                System.out.println(Thread.currentThread().getName() + ": " + count);
            }
        };


//        NotEnoughCounter notEnoughCounter = new NotEnoughCounter();
//
//        Runnable task = () -> {
//            for (int i=0; i<11; i++) {
//                notEnoughCounter.inc();
//            }
//        };
//
//
        Thread thread1 = new Thread(task);
        Thread thread2 = new Thread(task);

        thread1.start();
        thread2.start();

    }


}
