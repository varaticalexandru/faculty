package org.synchronized_keyword;

public class MultipleMonitorObjects {

    private Object monitor1 = new Object(); // monitor for counter1
    private Object monitor2 = new Object(); // monitor for counter2

    private int counter1 = 0;
    private int counter2 = 0;

    public void incCounter1() {
        synchronized (monitor1) {
            this.counter1++;
        }
    }

    public void incCounter2() {
        synchronized (monitor2) {
            this.counter2++;
        }
    }
}
