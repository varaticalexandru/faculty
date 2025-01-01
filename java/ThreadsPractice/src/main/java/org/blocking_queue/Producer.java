package org.blocking_queue;

import java.util.concurrent.BlockingQueue;

import static org.create_start_stop_threads.Ex_7.sleep;

public class Producer implements Runnable {

    private BlockingQueue<String> queue;

    public Producer(BlockingQueue<String> queue) {
        this.queue = queue;
    }

    @Override
    public void run() {
        while (true) {
            long timeMillis = System.currentTimeMillis();
            try {
                this.queue.put("" + timeMillis); // blocking
            } catch (InterruptedException exception) {
                System.out.println("Producer was interrupted");
            }
            sleep(1000);
        }
    }
}
