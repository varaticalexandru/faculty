package org.virtual_threads;

import java.util.ArrayList;
import java.util.List;

public class Ex_2 {
    public static void main(String[] args) throws InterruptedException {

        int num = 100_000;
        List<Thread> threadList = new ArrayList<>();

        for (int i = 1; i < num; i++) {
            int index = i;
            Thread thread_i = Thread.ofVirtual().start(() -> {
                int result = 1;
                for (int j = 0; j < 10; j++) {
                    result *= (j + 1);
                }
                System.out.println("Result[" + index + "]: " + result);
            });

            threadList.add(thread_i);
        }

        for (Thread thread: threadList
             ) {
            thread.join();
        }

    }
}
