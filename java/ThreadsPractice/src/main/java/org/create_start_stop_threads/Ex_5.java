package org.create_start_stop_threads;

public class Ex_5 {
    public static void main(String[] args) throws InterruptedException {

        MyRunnable runnable = new MyRunnable();
        Thread thread = new Thread(runnable, "Thread-1");
        thread.start();

        Thread.sleep(5000);

        runnable.requestStop();

    }

    public static class MyRunnable implements Runnable {

        private boolean stopRequested = false;

        public synchronized void requestStop() {
            this.stopRequested = true;
        }

        public synchronized boolean isStopRequested() {
            return this.stopRequested;
        }

        private void sleep(long millis) {
            try {
                Thread.sleep(millis);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }


        @Override
        public void run() {
            System.out.println(Thread.currentThread().getName() + " running");

            while (!isStopRequested()) {
                sleep(1000);
                System.out.println("...");
            }

            System.out.println(Thread.currentThread().getName() + " stopped");
        }
    }

}
