package org.executor_service;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class ExecutorService2 {

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(1);

        Future future = executorService.submit(newRunnable("Task1.1"));

        System.out.println("is done: " + future.isDone());

        try {
             future.get();  // blocking
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }

        System.out.println("is done: " + future.isDone());

        executorService.shutdown();
    }

    private static Runnable newRunnable(String msg) {
        return () -> {
            System.out.println(Thread.currentThread() + ": " + msg);
        };
    }
}
