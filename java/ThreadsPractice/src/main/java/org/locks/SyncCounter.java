package org.locks;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class SyncCounter {

    private int count = 0;

    private final Lock lock = new ReentrantLock();

    public void incCount() {
        try {
            lock.lock();
            this.count++;   // critical section
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            lock.unlock();
        }
    }

    public int getCount() {
        try {
            lock.lock();
            return this.count; // critical operation
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            lock.unlock();
        }
    }

}
