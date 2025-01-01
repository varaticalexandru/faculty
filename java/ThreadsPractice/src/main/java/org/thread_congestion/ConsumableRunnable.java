package org.thread_congestion;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;

public class ConsumableRunnable implements Runnable {

    private final BlockingQueue<String> queue;
    private AtomicBoolean keepRunning  = new AtomicBoolean(true);

    public ConsumableRunnable(BlockingQueue queue) {
        this.queue = queue;
    }

    public void stop() {
        System.out.println(Thread.currentThread().getName() + ": stopping thread");
        this.keepRunning.set(false);
    }


    @Override
    public void run() {

        System.out.println(Thread.currentThread().getName() + ": started");

        long objectsConsumed = 0L;

        while (this.keepRunning.get()) {
            String consumed = takeObjectFromQueue();
            if (consumed != null) { objectsConsumed++; }
        }

        System.out.println(Thread.currentThread().getName() + " consumed: " + objectsConsumed);
        System.out.println(Thread.currentThread().getName() + ": finished");
    }

    private String takeObjectFromQueue() {
        try {
            return queue.poll(1000, TimeUnit.MILLISECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
            return null;
        }
    }
}
