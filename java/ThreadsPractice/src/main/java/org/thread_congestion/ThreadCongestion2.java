package org.thread_congestion;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class ThreadCongestion2 {

    public static void main(String[] args) {

        int objects_to_produce = 1_000_000;

        BlockingQueue[] queues = new BlockingQueue[3];
        ConsumableRunnable[] consumerRunnables = new ConsumableRunnable[3];

        for (int i = 0; i < queues.length; i++) {
            queues[i] = new ArrayBlockingQueue<String>(objects_to_produce);
        }

        synchronized (ThreadCongestion2.class) {
            for (int i = 0; i < consumerRunnables.length; i++) {
                consumerRunnables[i] = new ConsumableRunnable(queues[i]);
                Thread consumingThread = new Thread(consumerRunnables[i]);
                consumingThread.start();
            }
        }

        Thread producingThread = new Thread(() -> {
            for (int i = 0; i < objects_to_produce; i++) {
                try {
                    queues[i % queues.length].put("" + i);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }

            System.out.println("All objects produced, number: " + objects_to_produce);

            synchronized (ThreadCongestion2.class) {
                for (int i = 0; i < consumerRunnables.length; i++) {
                    consumerRunnables[i].stop();
                }
            }
        });

        producingThread.start();
    }


}
