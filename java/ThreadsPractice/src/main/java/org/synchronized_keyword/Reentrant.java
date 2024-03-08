package org.synchronized_keyword;

public class Reentrant {

    private int count = 0;

    // both methods are synchronized on the same monitor object (Reentrant's instance)
    public synchronized void inc() {
        this.count++;
    }

    public synchronized int incAndGet() {
        inc();
        return this.count;
    }
}
