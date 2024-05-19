package org.thread_local;


public class ThreadLocalLazyInitialization {

    public static void main(String[] args) {

        ThreadLocal<String> threadLocal = new ThreadLocal<>();

        if (threadLocal.get() == null) {
            threadLocal.set("Lazily set value");
        }

        System.out.println(threadLocal.get());

    }

}
