package org.example;

import java.util.ArrayList;
import java.util.List;

public class Main {

    public static void sleep(long millis) {
        try {
            Thread.sleep(millis);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {

        List<Thread> vThreads = new ArrayList<>();
        int vThreadCount = 100_000;

        for (int i=0; i<vThreadCount; i++) {
            int vThreadIndex = i;
            Thread vThread = Thread.ofVirtual().start(() -> {
                int result = 1;
                for (int j = 0; j < 10; j++)
                    result *= j+1;
                System.out.println("Result[" + vThreadIndex + "]: " + result);
            });

            vThreads.add(vThread);
        }

        for (int i=0; i<vThreadCount; i++) {
            try {
                vThreads.get(i).join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }


    }
}