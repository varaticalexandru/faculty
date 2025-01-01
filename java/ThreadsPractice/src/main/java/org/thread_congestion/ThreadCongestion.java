package org.thread_congestion;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class ThreadCongestion {

    public static void main(String[] args) {

        int objects_to_produce = 1_000_000;

        BlockingQueue<String> queue = new ArrayBlockingQueue<>(objects_to_produce);
        ConsumableRunnable[] consumerRunnables = new ConsumableRunnable[3];

        synchronized (ThreadCongestion.class) {
            for (int i = 0; i < consumerRunnables.length; i++) {
                consumerRunnables[i] = new ConsumableRunnable(queue);
                Thread consumingThread = new Thread(consumerRunnables[i]);
                consumingThread.start();
            }
        }

        Thread producingThread = new Thread(() -> {
            for (int i = 0; i < objects_to_produce; i++) {
                try {
                    queue.put("" + i);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }

            System.out.println("All objects produced, number: " + objects_to_produce);

            synchronized (ThreadCongestion.class) {
                for (int i = 0; i < consumerRunnables.length; i++) {
                    consumerRunnables[i].stop();
                }
            }
        });

        producingThread.start();
    }


}
