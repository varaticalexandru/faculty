package org.race_conditions;

public class Counter implements Countable {

    private int count = 0;

    public int incAndGetCount() {
        this.count++;
        return this.count;
    }

    public int getCount() {
        return this.count;
    }

    public void incCount() {
        this.count++;
    }
}
