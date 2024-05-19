package org.executor_service;

import java.util.concurrent.*;

public class ExecutorService1 {

    public static void main(String[] args) {

        int corePoolSize = 10;
        int maxPoolSize = 20;
        long keepAliveTime = 3000;

//        ExecutorService executorService = (ThreadPoolExecutor) Executors.newFixedThreadPool(10);
//        ScheduledExecutorService scheduledExecutorService = new ScheduledThreadPoolExecutor(corePoolSize);
//        ExecutorService executorService = Executors.newSingleThreadExecutor();

        ExecutorService executorService = new ThreadPoolExecutor(
                corePoolSize,
                maxPoolSize,
                keepAliveTime,
                TimeUnit.MILLISECONDS,
                new ArrayBlockingQueue<>(128)
        );

        executorService.execute(newRunnable("Task1"));
        executorService.execute(newRunnable("Task2"));
        executorService.execute(newRunnable("Task3"));

        executorService.shutdown();

    }

    private static Runnable newRunnable(String msg) {
        return () -> {
            System.out.println(Thread.currentThread() + ": " + msg);
        };
    }
}
