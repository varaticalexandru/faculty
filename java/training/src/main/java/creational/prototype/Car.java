package creational.prototype;

public class Car extends Vehicle {

    // members

    private int topSpeed;

    // getters

    public int getTopSpeed() {
        return topSpeed;
    }
    public void setTopSpeed(int topSpeed) {
        this.topSpeed = topSpeed;
    }

    // constructors
    public Car(String brand, String model, String color, int topSpeed) {

        super(brand, model, color);
        this.topSpeed = topSpeed;
    }

    public Car(Car car) {
        super(car);
        this.topSpeed = car.topSpeed;
    }


    // methods
    @Override
    public Car clone() {
        return new Car(this);
    }
}
