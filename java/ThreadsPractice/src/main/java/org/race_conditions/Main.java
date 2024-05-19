package org.race_conditions;

public class Main {

    public static void main(String[] args) {

//        Countable counter = new Counter();
        Countable counter = new SyncCounter();

        Thread thread1 = new Thread(getTask(counter, "Thread1 final count: "));
        Thread thread2 = new Thread(getTask(counter, "Thread2 final count: "));

        thread1.start();
        thread2.start();
    }


    private static Runnable getTask(Countable counter, String message) {
        return () -> {
            for (int i = 0; i < 1_000_000; i++)
                counter.incCount();

            System.out.println(message + counter.getCount());
        };
    }


}
