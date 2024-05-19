package org.locks;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockInterruptibly {

    public static void main(String[] args) {

        Lock lock = new ReentrantLock(false);

        Runnable task = () -> {
            try {
                Thread.currentThread().interrupt();
                lock.lockInterruptibly();
                System.out.println("Working");
                lock.unlock();
            } catch (Exception e) {
                throw new RuntimeException("Thread interrupted", e);
            } finally {
                lock.unlock();
            }
        };

        Thread thread1 = new Thread(task);
        thread1.start();
    }

}
