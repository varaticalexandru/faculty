package org.compare_and_swap;

import java.util.concurrent.atomic.AtomicLong;

public interface MyCounter {
    void inc();
    AtomicLong get();
}
