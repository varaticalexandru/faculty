package org.volatile_;

public class NotEnoughCounter {

    private volatile int count = 0;

    public boolean inc() {

        if (this.count == 10)
            return false;

        this.count++;
        // reads (from RAM)
        // increments locally (stores in CPU register, caches)
        // flushes (to RAM)
        return true;
    }

    public int getCount() {
        return count;
    }
}
