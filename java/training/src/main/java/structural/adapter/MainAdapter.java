package structural.adapter;

public class MainAdapter {
    public static void main(String[] args) {

        AssignmentWork aw = new AssignmentWork();
        Pen p = new PenAdapter();
        //aw.setP(p);
        aw.writeAssignment("I'm bit tired to write an assignment");
    }
}
