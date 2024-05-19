package org.race_conditions;

public class SyncCounter implements Countable {

    private int count = 0;

    @Override
    public int incAndGetCount() {
        synchronized (this) {
            this.count++;
            return this.count;
        }
    }

    @Override
    public int getCount() {
        synchronized (this) {
            return this.count;
        }
    }

    @Override
    public void incCount() {
        synchronized (this) {
            this.count++;
        }
    }
}
