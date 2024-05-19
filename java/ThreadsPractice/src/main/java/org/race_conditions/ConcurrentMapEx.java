package org.race_conditions;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class ConcurrentMapEx {

    public static void main(String[] args) {

        ConcurrentMap<String, String> concurrentMap = new ConcurrentHashMap();

        Thread thread1 = new Thread(getTask(concurrentMap));
        Thread thread2 = new Thread(getTask(concurrentMap));

        thread1.start();
        thread2.start();


    }

    public static Runnable getTask(Map<String, String> sharedMap) {
        return () -> {
            for (int i = 0; i < 1_000_000; i++) {
                synchronized (sharedMap) {  // adds synchronization between threads accessing the map
                    if (sharedMap.containsKey("key")) {
                        String val = sharedMap.remove("key");
                        if (val == null)
                            System.out.println("Iteration: " + i + ": value for 'key' is null.");
                    } else {
                        sharedMap.put("key", "value");
                    }
                }
            }
        };
    }
}
