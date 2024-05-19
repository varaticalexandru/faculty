package org.executor_service_2;

import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class ExecutorService1 {

    public static void main(String[] args) {

        ExecutorService executorService = Executors.newFixedThreadPool(3);

//        executorService.shutdown(); // blocking: initiates shutdown of active tasks (in execution)

        List<Runnable> runnables = executorService.shutdownNow(); // non-blocking: returns remaining queued tasks

        try {
            boolean awaitedTermination = executorService.awaitTermination(3000, TimeUnit.MILLISECONDS);
            System.out.println(awaitedTermination);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }
}
