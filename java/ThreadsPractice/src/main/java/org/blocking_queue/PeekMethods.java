package org.blocking_queue;

import java.util.NoSuchElementException;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class PeekMethods {
    public static void main(String[] args) {

        BlockingQueue<String> queue = new ArrayBlockingQueue(3);

        String peek = queue.peek();

        try {
            String element = queue.element();
        } catch (NoSuchElementException e) {
            System.out.println("Blocking queue is empty.");
        }
    }

}
