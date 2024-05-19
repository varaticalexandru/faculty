package org.race_conditions;

public class DifferentCounters {

    public static void main(String[] args) {

        Countable counter1 = new Counter();
        Countable counter2 = new Counter();

        Thread thread1 = new Thread(getTask(counter1, "Thread1"));
        Thread thread2 = new Thread(getTask(counter2, "Thread2"));

        thread1.start();
        thread2.start();
    }


    private static Runnable getTask(Countable counter, String message) {
        return () -> {
            for (int i = 0; i < 1_000_000; i++)
                counter.incCount();

            System.out.println(message + " final count : " + counter.getCount());
        };
    }
}
