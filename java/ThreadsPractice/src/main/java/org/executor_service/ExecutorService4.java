package org.executor_service;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

public class ExecutorService4 {

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(1);

        List<Callable<String>> callables = new ArrayList<>();
        callables.add(newCallable("Task1.1"));
        callables.add(newCallable("Task1.2"));
        callables.add(newCallable("Task1.3"));

        String result;
        try {
            result = (String) executorService.invokeAny(callables);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        } catch (ExecutionException e) {
            throw new RuntimeException(e);
        }

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
