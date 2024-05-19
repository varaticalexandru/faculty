package org.executor_service_2;

import java.util.concurrent.*;

public class ExecutorService2 {

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(3);

        Future<String> future = executorService.submit(newCallable("Thread1"));

        boolean wasCancelled = future.cancel(true);
        System.out.println("Was cancelled: " + wasCancelled);

        try {
            String result = future.get();
        } catch (InterruptedException e) {

        } catch (ExecutionException e) {

        } catch (CancellationException e) {
            System.out.println("Cannot call get() on Future since task was cancelled.");
        }

        System.out.println("Is cancelled: " + future.isCancelled());
        System.out.println("Is done: " + future.isDone());

        executorService.shutdown();
    }


    private static Callable<String> newCallable(String msg) {
        return () -> {
            Thread.sleep(3000);
            return Thread.currentThread() + ": " + msg;
        };
    }
}
