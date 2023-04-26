package structural.adapter;

public class AssignmentWork {

    // members
    private Pen p;

    // getters & setters
    public Pen getP() {
        return p;
    }
    public void setP(Pen p) {
        this.p = p;
    }

    // methods
    public void writeAssignment(String str) {
        p.write(str);
    }
}
