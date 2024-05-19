package org.volatile_;

public class Exchanger {

    private Object object = null;
    private volatile boolean hasNewObject = false;  // visibility guarantees + happens before guarantees

    public void setObject(Object obj) {
        this.object = obj;
        this.hasNewObject = true;   // flushes both object and hasNewObject to RAM; doesn't allow instruction reordering (volatile var instruction wont get reordered to happen before the other non-volatile one)
    }

    public Object getObject() {
        // busy wait
        while (!this.hasNewObject) {}   // reads fresh values of hasNewObject (and object) directly from RAM every time

        Object returnedVal = this.object;
        this.hasNewObject = false;      // flushes hasNewObject and object to RAM
        return returnedVal;
    }


}
