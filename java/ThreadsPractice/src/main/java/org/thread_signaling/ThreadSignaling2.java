package org.thread_signaling;

public class ThreadSignaling2 {
    public static void main(String[] args) {

        SignalCarrier signalCarrier = new SignalCarrier();

        Thread waiter = new Thread(() -> {
            try {
                signalCarrier.doWait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        });

        Thread notifier = new Thread(() -> {
           signalCarrier.doNotify();
        });

        waiter.start();
        notifier.start();

    }
}
