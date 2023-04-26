package creational.builder.phone;

public class PhoneBuilder {
    // members
    private String os;
    private String cpu;
    private double screenSize;
    private int battery;
    private double camera;


    // setters
    public PhoneBuilder setOS(String os) {
        this.os = os;
        return this;
    }

    public PhoneBuilder setCPU(String cpu) {
        this.cpu = cpu;
        return this;
    }

    public PhoneBuilder setScreenSize(double screenSize) {
        this.screenSize = screenSize;
        return this;
    }

    public PhoneBuilder setBattery(int battery) {
        this.battery = battery;
        return this;
    }

    public PhoneBuilder setCamera(double camera) {
        this.camera = camera;
        return this;
    }

    // methods
    public Phone getPhone() {
        return new Phone(os, cpu, screenSize, battery, camera);
    }

}
