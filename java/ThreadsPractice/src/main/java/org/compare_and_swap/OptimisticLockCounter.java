package org.compare_and_swap;

import java.util.concurrent.atomic.AtomicLong;

public class OptimisticLockCounter implements MyCounter {

    private final AtomicLong count = new AtomicLong();

    @Override
    public void inc() {
        boolean incSuccessful = false;
        while (!incSuccessful) {
            long currentVal = this.count.get();
            long incVal = currentVal + 1;

            incSuccessful = this.count.compareAndSet(currentVal, incVal);
        }
    }

    @Override
    public AtomicLong get() {
        return this.count;
    }
}
