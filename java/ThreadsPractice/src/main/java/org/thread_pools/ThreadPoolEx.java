package org.thread_pools;

public class ThreadPoolEx {

    public static void main(String[] args) {

        ThreadPool threadPool = new ThreadPool(3, 10);

        for (int i = 0; i < 10; i++) {
            int taskNo = i;
            threadPool.execute(() -> {
                System.out.println(Thread.currentThread().getName() + " Task: " + taskNo);
            });
        };

        threadPool.waitUntilAllTasksFinished();
        threadPool.stop();

    }


}
