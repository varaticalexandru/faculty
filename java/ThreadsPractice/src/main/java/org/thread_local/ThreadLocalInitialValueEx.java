package org.thread_local;

public class ThreadLocalInitialValueEx {

    public static void main(String[] args) {
        ThreadLocal<Object> threadLocal1 = new ThreadLocal<>() {
            @Override
            protected Object initialValue() {
                return new Object();
            }
        };

        ThreadLocal<Object> threadLocal2 = ThreadLocal
                .withInitial(Object::new);

        // individual objects for each thread accessing each ThreadLocal
        Thread thread1 = new Thread(() -> {
            System.out.println(threadLocal1.get());
            System.out.println(threadLocal2.get());
        });

        Thread thread2 = new Thread(() -> {
            System.out.println(threadLocal1.get());
            System.out.println(threadLocal2.get());
        });

        thread1.start();
        thread2.start();
    }

}
