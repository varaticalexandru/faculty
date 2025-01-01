package org.false_sharing;

public class FalseSharing {

    public static void main(String[] args) {

        Counter1 counter1 = new Counter1();
        Counter1 counter2 = counter1;
//        Counter1 counter2 = new Counter1();

        long iterations = 1_000_000_000;

        Thread thread1 = new Thread(() -> {
            String threadName = Thread.currentThread().getName();
            long startTime = System.currentTimeMillis();
            for (int i = 0; i < iterations; i++) {
                counter1.count1++;
            }
            long endTime = System.currentTimeMillis();

            System.out.println(threadName + ": total time: " + (endTime - startTime));
        });

        Thread thread2 = new Thread(() -> {
            String threadName = Thread.currentThread().getName();
            long startTime = System.currentTimeMillis();
            for (int i = 0; i < iterations; i++) {
                counter2.count2++;
            }
            long endTime = System.currentTimeMillis();

            System.out.println(threadName + ": total time: " + (endTime - startTime));
        });

        thread1.start();
        thread2.start();
    }
}
