package org.blocking_queue;

import java.util.concurrent.BlockingQueue;

public class Consumer implements Runnable {

    private final BlockingQueue<String> queue;

    public Consumer(BlockingQueue<String> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        while (true) {
            try {
                String taken = queue.take();    // blocking
                System.out.println("Consumed: " + taken);
            } catch (InterruptedException exception) {
                System.out.println("Consumer was interrupted.");
                exception.printStackTrace();
            }
        }
    }
}
