package org.volatile_;

public class Exchanger2 {

    private int val1;
    private int val2;
    private volatile int val3;  // visibility guarantees + happens before guarantees

    public void setValues(Values src) {
        this.val1 = src.val1;
        this.val2 = src.val2;

        this.val3 = src.val3; // flushes val3 (alongside val1 and val2) to RAM + won't get reordered to happen before the other 2 instructions
    }

    public void getValues(Values dest) {
        dest.val3 = this.val3; // reads val3 (alongside val1 and val2) from RAM + won't get reordered

        dest.val1 = this.val1;
        dest.val2 = this.val2;
    }
}
