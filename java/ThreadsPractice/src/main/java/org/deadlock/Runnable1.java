package org.deadlock;

import java.util.concurrent.locks.Lock;

public class Runnable1 implements Runnable {

    private Lock lock1;
    private Lock lock2;

    public Runnable1 (Lock lock1, Lock lock2) {
        this.lock1 = lock1;
        this.lock2 = lock2;
    }

    @Override
    public void run() {

        // lock lock-1
        System.out.println(Thread.currentThread().getName() +  ": attempt locking lock-1 ...");
        this.lock1.lock();
        System.out.println(Thread.currentThread().getName() +  ": locked lock-1.");

        try {
            Thread.sleep(3000);
        } catch (InterruptedException exception) {
            // ignore
        }

        // lock lock-2
        System.out.println(Thread.currentThread().getName() + ": attempt locking lock-2 ...");
        this.lock2.lock();
        System.out.println(Thread.currentThread().getName() +  ": locked lock-2.");

        // work to do

        // unlock
        System.out.println(Thread.currentThread().getName() + ": unlocking lock-2");
        this.lock2.unlock();

        System.out.println(Thread.currentThread().getName() + ": unlocking lock-1");
        this.lock1.unlock();

    }
}
