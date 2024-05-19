package org.race_conditions;

public class OneReadsOneWrites {

    public static void main(String[] args) {

        Countable counter = new Counter();
//        Countable counter = new SyncCounter();

        Thread thread1 = new Thread(getWritingTask(counter, "Thread1 final count: "));
        Thread thread2 = new Thread(getReadingTask(counter));

        thread1.start();
        thread2.start();


    }


    private static Runnable getWritingTask(Countable counter, String message) {
        return () -> {
            for (int i = 0; i < 1_000_000; i++)
                counter.incCount();

            System.out.println(message + counter.getCount());
        };
    }


    private static Runnable getReadingTask(Countable counter) {
        return () -> {
            for (int i = 0; i < 10; i++) {
                try {
                    Thread.sleep(1);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

                System.out.println(counter.getCount());

            }
        };
    }
}
