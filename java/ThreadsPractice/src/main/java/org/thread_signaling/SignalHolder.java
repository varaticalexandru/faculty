package org.thread_signaling;

public class SignalHolder {

    private boolean isThreadWaiting = false;
    private boolean signalRaised = false;


    public void doWait() throws InterruptedException {
        synchronized (this) {
            if (this.signalRaised) {
                this.signalRaised = false;
                return;
            }
            System.out.println(Thread.currentThread().getName() + ": calling wait()");
            this.isThreadWaiting = true;
            this.wait();
            this.isThreadWaiting = false;
            System.out.println(Thread.currentThread().getName() + ": exited wait()");
        }
    }

    public void doNotify() {
        synchronized (this) {
            System.out.println(Thread.currentThread().getName() + ": calling notify()");
            if (!this.isThreadWaiting) {
                this.signalRaised = true;
            }
            this.notify();
            System.out.println(Thread.currentThread().getName() + ": exited notify()");
        }
    }

    public void doNotifyAll() {
        synchronized (this) {
            System.out.println(Thread.currentThread().getName() + ": calling notifyAll()");
            this.notifyAll();
            System.out.println(Thread.currentThread().getName() + ": exited notifyAll()");
        }
    }
}
