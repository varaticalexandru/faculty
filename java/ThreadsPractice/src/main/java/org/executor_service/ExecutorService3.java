package org.executor_service;

import java.util.concurrent.*;

public class ExecutorService3 {

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(1);

        Future future = executorService.submit(newCallable("Task1.1"));

        System.out.println("is done: " + future.isDone());


        String result;
        try {
            result = (String) future.get();  // blocking
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }

        System.out.println("is done: " + future.isDone());
        System.out.println(result);

        executorService.shutdown();
    }

    private static Callable<String> newCallable(String msg) {
        return () -> {
            Thread.sleep(3000);
            return Thread.currentThread() + ": " + msg;
        };
    }
}
