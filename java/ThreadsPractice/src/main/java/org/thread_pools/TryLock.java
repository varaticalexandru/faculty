package org.thread_pools;

import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class TryLock {

    /*
    *   Differences between LOCKS and SYNCHRONIZED BLOCKS
    *
    * 1) SYNCHRONIZED BLOCKS can never span more than one method, while LOCKS can be locked/unlocked from different methods.
    *
    * 2) LOCKS provide the same visibility and happens-before guarantees as SYNCHRONIZED BLOCKS.
    *
    * 3) SYNCHRONIZED BLOCKS are always reentrant, LOCKS can decide not to be.
    *
    * 4) SYNCHRONIZED BLOCKS do not guarantee fairness, LOCKS can.
    *
    * */

    public static void main(String[] args) {

        Lock lock = new ReentrantLock(true);

        Runnable task = () -> {
            try {
//                boolean lockResult = lock.tryLock();
                boolean lockResult = lock.tryLock(1000, TimeUnit.MILLISECONDS);
                System.out.println("Lock successful: " + lockResult);
                System.out.println("Working");
            } catch (Exception e) {
                throw new RuntimeException(e);
            } finally {
                lock.unlock();
            }
        };

        Thread thread =  new Thread(task);
        thread.start();
    }

    public static void ReentrantLockMethods() {
        ReentrantLock lock = new ReentrantLock(true);

        lock.getHoldCount();
        lock.getQueueLength();
        lock.hasQueuedThreads();
        lock.hasQueuedThread(Thread.currentThread());
        lock.isFair();
        lock.isLocked();
        lock.isHeldByCurrentThread();

    }

}
