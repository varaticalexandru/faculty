package org.blocking_queue;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class AdditionalMethods {

    public static void main(String[] args) {

        BlockingQueue<String> queue = new ArrayBlockingQueue(3);

        int size = queue.size();

        int remainingCapacity = queue.remainingCapacity();

        boolean contains = queue.contains("1");
    }
}
