package org.synchronized_keyword;

public class SynchronizedExchanger {
    protected Object object = null;

    public synchronized void setObject(Object o) {
        this.object = o;
    }

    public void setObj(Object o) {
        synchronized(this) {
            this.object = o;
        }
    }


    public synchronized Object getObject() {
        return this.object;
    }

    public synchronized Object getObj() {
        synchronized (this) {
            return this.object;
        }
    }
}
