package org.locks;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class LockEx {

    public static void main(String[] args) {

        Lock lock = new ReentrantLock(true);

        lock.lock();
        // operation
        lock.unlock();
    }
}
