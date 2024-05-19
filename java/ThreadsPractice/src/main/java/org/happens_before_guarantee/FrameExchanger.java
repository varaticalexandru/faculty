package org.happens_before_guarantee;

public class FrameExchanger {

    private long framesStoredCount = 0;
    private long framesTakenCount = 0;

    private volatile boolean hasNewFrame = false; // visibility guarantee (all other vars visible to the thread will also be flushed/read to/from main memory alongside this one)
    private Frame frame = null;

    public void storeFrame(Frame frame) {
        this.frame = frame;
        this.framesStoredCount++;
        this.hasNewFrame = true;    // happens before guarantee (because volatile, the instruction won't be reordered before the other 2)
    }

    public Frame takeFrame() {
        // busy until new frame arrives
        while (!hasNewFrame) {}

        Frame takenFrame = this.frame;
        this.framesTakenCount++;
        this.hasNewFrame = false;   // happens before guarantee (because volatile, the instruction won't be reordered before the other 3)

        return takenFrame;
    }
}
