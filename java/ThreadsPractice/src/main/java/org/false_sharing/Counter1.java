package org.false_sharing;

//@jdk.internal.vm.annotation.Contended
public class Counter1 {

    public volatile long count1 = 0;

    public volatile long count2 = 0;
}
