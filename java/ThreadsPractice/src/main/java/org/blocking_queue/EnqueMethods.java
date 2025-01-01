package org.blocking_queue;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;

public class EnqueMethods {

    public static void main(String[] args) {

        BlockingQueue<String> queue = new ArrayBlockingQueue<>(3);

        try {
            queue.put("1");     // blocking
        } catch (InterruptedException exception) {
            throw new RuntimeException(exception);
        }

        try {
            boolean wasEnqueued = queue.add("2");   // non-blocking
        } catch (IllegalStateException exception) {
            // no space
            throw new RuntimeException(exception);
        }

        boolean wasEnqueued = queue.offer("3");    // non-blocking

        try {
            boolean wasEnqueued2 = queue.offer("4", 1000, TimeUnit.MILLISECONDS);   // blocking
        } catch(InterruptedException exception) {
            throw new RuntimeException(exception);
        }
    }
}
