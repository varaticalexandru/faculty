package org.thread_signaling;

public class ThreadSignaling1 {
    public static void main(String[] args) {

        Object signalObject = new Object();

        Thread waiter = new Thread(() -> {
            synchronized (signalObject) {
                try {
                    signalObject.wait();
                } catch (InterruptedException exception) {
                    exception.printStackTrace();
                }
                //
            }
        });

        Thread notifier = new Thread(() -> {
            synchronized (signalObject) {
                try {
                    signalObject.notify();
                } catch (IllegalMonitorStateException exception) {
                    exception.printStackTrace();
                }
            }
        });

        waiter.start();
        notifier.start();

    }
}
