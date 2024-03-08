package org.synchronized_keyword;

public class MixedSynchronization {

    protected static Object staticObj = null;
    protected Object instanceObj = null;

    public static synchronized void setObject(Object o) {
        staticObj = o;
    }

    public synchronized void setObj(Object o) {
        this.instanceObj = o;
    }
}
