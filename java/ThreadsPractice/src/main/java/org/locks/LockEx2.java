package org.locks;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockEx2 {

    public static void main(String[] args) {

        Lock lock = new ReentrantLock(false);
        Runnable task = () -> {
            lockWorkUnlock(lock, 1000);
        };

        Thread thread1 = new Thread(task, "Thread1");
        Thread thread2 = new Thread(task, "Thread2");
        Thread thread3 = new Thread(task, "Thread3");

        thread1.start();
        thread2.start();
        thread3.start();

    }

    private static void lockWorkUnlock(Lock lock, long millis) {
        try {
            lock.lock();
            printThreadMsg("holds the lock.");
            Thread.sleep(1000);
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
        finally {
            lock.unlock();
        }
    }

    private static void printThreadMsg(String msg) {
        System.out.println(Thread.currentThread().getName() + " " + msg);
    }

}
