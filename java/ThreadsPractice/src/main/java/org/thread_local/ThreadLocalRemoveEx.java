package org.thread_local;

public class ThreadLocalRemoveEx {

    public static void main(String[] args) {

        ThreadLocal<String> threadLocal = new ThreadLocal<>();

        Thread thread1 = new Thread(() -> {
            threadLocal.set("Thread-1");
            System.out.println(threadLocal.get());

            threadLocal.remove();
            System.out.println(threadLocal.get());
        });

        Thread thread2 = new Thread(() -> {
           threadLocal.set("Thread-2");
            System.out.println(threadLocal.get());
           try {
               Thread.sleep(2000);
           } catch (InterruptedException ex) {
               ex.printStackTrace();
           }

           threadLocal.remove();
            System.out.println(threadLocal.get());
        });

        thread1.start();
        thread2.start();
    }
}
