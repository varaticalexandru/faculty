package org.deadlock_prevention;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;

import static org.create_start_stop_threads.Ex_7.sleep;


public class TimeoutRunnable2 implements Runnable {

    private final Lock lock1;
    private final Lock lock2;

    public TimeoutRunnable2(Lock lock1, Lock lock2) {
        this.lock1 = lock1;
        this.lock2 = lock2;
    }

    @Override
    public void run() {
        String threadName = Thread.currentThread().getName();

        while (true) {
            int failureCount = 0;
            while (!tryLockBothLocks()) {
                failureCount++;
                System.err.println(threadName + ": error locking both locks. Waiting a bit before retrying. Failure count: " + failureCount);
                sleep(100L *  ((long)Math.random()));
            }
            if (failureCount > 0) {
                System.out.println(threadName + " succeded in locking both locks after " + failureCount + " failures.");
            }

            // work, now that both locks are locked

            // unlock
            lock1.unlock();
            lock2.unlock();
        }
    }

    private boolean tryLockBothLocks() {
        String threadName = Thread.currentThread().getName();

        try {
            boolean tryLock2 = lock2.tryLock(1000, TimeUnit.MILLISECONDS);
            if (!tryLock2) {
                return false;
            }
        } catch (InterruptedException exception) {
            System.out.println(threadName + " failed locking lock 2.");
            return false;
        }


        try {
            boolean tryLock1 = lock1.tryLock(1000, TimeUnit.MILLISECONDS);
            if (!tryLock1) {
                lock2.unlock();
                return false;
            }
        } catch (InterruptedException exception) {
            System.out.println(threadName + " failed locking lock 1.");
            return false;
        }

        return true;
    }

}
