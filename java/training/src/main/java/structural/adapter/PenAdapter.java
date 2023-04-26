package structural.adapter;

public class PenAdapter implements Pen {

    // members
    PilotPen pp = new PilotPen();

    // methods
    @Override
    public void write(String str) {
        pp.mark(str);
    }
}
