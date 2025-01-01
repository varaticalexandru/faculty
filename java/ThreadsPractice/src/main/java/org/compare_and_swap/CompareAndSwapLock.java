package org.compare_and_swap;

import java.util.concurrent.atomic.AtomicBoolean;

public class CompareAndSwapLock implements MyLock {

    private final AtomicBoolean locked = new AtomicBoolean(false);

    public AtomicBoolean getLocked() {
        return this.locked;
    }

    @Override
    public void lock() {
        while(!locked.compareAndSet(false, true)) {
            // busy wait
        }

        // work
    }

    @Override
    public void unlock() {
        this.locked.set(false);
    }
}
