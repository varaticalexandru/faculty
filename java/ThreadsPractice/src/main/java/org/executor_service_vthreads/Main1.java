package org.executor_service_vthreads;

import java.util.concurrent.*;

public class Main1 {
    public static void main(String[] args) {

        ExecutorService executorService = Executors.newVirtualThreadPerTaskExecutor();

        executorService.submit(() -> {
            System.out.println("This is a Runnable executed by a virtual thread.");
        });

        Callable<String> callable = new Callable<>() {
            @Override
            public String call() throws Exception {
                System.out.println("Callable executed by a virtual thread.");
                return "Result from Callable.";
            }
        };

        Future<String> futureResult = executorService.submit(callable);

        try {
            System.out.println(futureResult.get());
        } catch (InterruptedException | ExecutionException exception) {
            throw new RuntimeException(exception);
        } finally {
            executorService.shutdown();
        }
    }
}
