package creational.builder.phone;

public class Phone {

    // members
    private String os;
    private String cpu;
    private double screenSize;
    private int battery;
    private double camera;



    // constructors
    public Phone(String os, String cpu, double screenSize, int battery, double camera) {
        this.os = os;
        this.cpu = cpu;
        this.screenSize = screenSize;
        this.battery = battery;
        this.camera = camera;
    }



    // methods
    @Override
    public String toString() {
        return "Phone{" +
                "os='" + os + '\'' +
                ", cpu='" + cpu + '\'' +
                ", screenSize=" + screenSize +
                ", battery=" + battery +
                ", camera=" + camera +
                '}';
    }

}
