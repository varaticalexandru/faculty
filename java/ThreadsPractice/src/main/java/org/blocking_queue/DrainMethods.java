package org.blocking_queue;

import java.util.ArrayList;
import java.util.Collection;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class DrainMethods {
    public static void main(String[] args) {

        BlockingQueue<String> queue = new ArrayBlockingQueue<>(3);
        Collection dest = new ArrayList();


        queue.drainTo(dest);
        queue.drainTo(dest, 5);
    }
}
