package org.locks;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ConcurrentCalculator {

    public static class Calculation {
        public int type;
        public int value;

        public static final int UNSPECIFIED = -1;
        public static final int ADDITION = 0;
        public static final int SUBTRACTION = 1;

        public Calculation(int type, int value) {
            this.type = type;
            this.value = value;
        }
    }

    private int result = 0;
    Lock lock = new ReentrantLock();

    public void add(int value) {
        try {
            lock.lock();
            result += value;
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            lock.unlock();
        }
    }

    public void subtract(int value) {
        try {
            lock.lock();
            result -= value;
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            lock.unlock();
        }
    }

    public void calculate(Calculation ... calculations) {

        try {
            lock.lock();

            for (Calculation calculation: calculations) {
                switch (calculation.type) {
                    case Calculation.ADDITION -> add(calculation.value);
                    case Calculation.SUBTRACTION -> subtract(calculation.value);
                }
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            lock.unlock();
        }
    }
}
