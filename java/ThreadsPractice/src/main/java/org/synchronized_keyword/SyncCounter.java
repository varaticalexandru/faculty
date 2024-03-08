package org.synchronized_keyword;

public class SyncCounter {

    private int count = 0;

    public void incCount() {
        synchronized (this) {
            this.count++;
        }
    }

    public int getCount() {
        synchronized (this) {
            return this.count;
        }
    }

    public int incAndGetCount() {
        synchronized (this) {
            this.count++;
            return this.count;
        }
    }

    public static void main(String[] args) {

        SyncCounter syncCounter = new SyncCounter();

        Runnable task = new Runnable() {
            @Override
            public void run() {
                for (int i = 0; i < 1_000; i++) {
                    System.out.println(syncCounter.incAndGetCount());
                }
            }
        };


        Thread thread1 = new Thread(task);
        Thread thread2 = new Thread(task);

        thread1.start();
        thread2.start();

    }
}
