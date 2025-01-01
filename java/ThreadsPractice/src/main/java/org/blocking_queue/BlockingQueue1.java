package org.blocking_queue;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class BlockingQueue1 {
    public static void main(String[] args) throws InterruptedException {
        BlockingQueue<String> queue = new ArrayBlockingQueue<>(3);

        queue.put("hey");
        queue.put("buddy");

        String taken1 = queue.take();
        String taken2 = queue.take();

        System.out.println("taken1 = " + taken1);
        System.out.println("taken2 = " + taken2);

    }
}
