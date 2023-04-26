package creational.prototype;

public class Bus extends Vehicle {

    // members

    private int wheels;

    // getters

    public int getWheels() {
        return wheels;
    }
    public void setWheels(int wheels) {
        this.wheels = wheels;
    }

    // constructors
    public Bus(String brand, String model, String color, int wheels) {

        super(brand, model, color);
        this.wheels = wheels;
    }

    public Bus(Bus bus) {
        super(bus);
        this.wheels = bus.wheels;
    }

    // methods
    @Override
    public Bus clone() {
        return new Bus(this);
    }
}
