package org.deadlock;

import java.util.concurrent.locks.Lock;

public class SyncRunnable1 implements Runnable {

    private final Lock lock1;
    private final Lock lock2;

    public SyncRunnable1(Lock lock1, Lock lock2) {
        this.lock1 = lock1;
        this.lock2 = lock2;
    }

    @Override
    public void run() {

        System.out.println(Thread.currentThread().getName() +  ": attempt locking lock-1 ...");
        // lock lock-1
        synchronized (lock1) {
            System.out.println(Thread.currentThread().getName() +  ": locked lock-1.");

            try {
                Thread.sleep(3000);
            } catch (InterruptedException exception) {
                // ignore
            }

            System.out.println(Thread.currentThread().getName() + ": attempt locking lock-2 ...");

            // lock lock-2
            synchronized (lock2) {
                System.out.println(Thread.currentThread().getName() +  ": locked lock-2.");
            }

            // work to do
        }

    }
}
