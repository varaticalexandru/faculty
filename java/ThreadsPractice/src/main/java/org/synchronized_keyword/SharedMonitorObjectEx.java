package org.synchronized_keyword;

public class SharedMonitorObjectEx {

    public static void main(String[] args) {

        Object monitor1 = new Object();
        SharedMonitorObject sm1 = new SharedMonitorObject(monitor1);
        SharedMonitorObject sm2 = new SharedMonitorObject(monitor1);

        // these calls will be blocked across threads because of the common object monitor
        sm1.incCounter();
        sm2.incCounter();


        Object monitor2 = new Object();
        SharedMonitorObject sm3 = new SharedMonitorObject(monitor2);

        // this call will not be blocked
        sm3.incCounter();
    }
}
