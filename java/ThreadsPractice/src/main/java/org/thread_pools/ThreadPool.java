package org.thread_pools;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class ThreadPool {
    private BlockingQueue<Runnable> taskQueue;
    private List<PoolThreadRunnable> runnables = new ArrayList<>();
    private boolean isStopped = false;

    public ThreadPool(int threadsNumber, int maxTasksNumber) {

        taskQueue = new ArrayBlockingQueue<>(maxTasksNumber);

        for (int i = 0; i < threadsNumber; i++) {
            PoolThreadRunnable runnable = new PoolThreadRunnable(taskQueue);

            runnables.add(runnable);
        }

        for(Runnable runnable: runnables)
            new Thread(runnable).start();
    }

    public synchronized void execute (Runnable task) {
        if (this.isStopped)
            throw new IllegalStateException("Threadpool is stopped.");

        this.taskQueue.offer(task);
    }

    public synchronized void stop() {
        this.isStopped = true;
        for(PoolThreadRunnable runnable: runnables)
            runnable.doStop();
    }

    public synchronized void waitUntilAllTasksFinished() {
        while (!this.taskQueue.isEmpty()) {
            try {
                Thread.sleep(1);

            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }
    }
}
