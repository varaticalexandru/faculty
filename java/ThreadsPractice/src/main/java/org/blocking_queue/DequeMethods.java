package org.blocking_queue;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class DequeMethods {

    public static void main(String[] args) {

        BlockingQueue<String> queue = new ArrayBlockingQueue<>(3);

        try {
            String taken = queue.take();    // blocking
        } catch (InterruptedException exception) {
            throw new RuntimeException(exception);
        }

        String taken2 = queue.poll();    // non-blocking

        try {
            String taken3 = queue.poll(1000, TimeUnit.MILLISECONDS);   // blocking
        } catch(InterruptedException exception) {
            throw new RuntimeException(exception);
        }

        boolean removed = queue.remove("1");    // non-blocking
    }
}
