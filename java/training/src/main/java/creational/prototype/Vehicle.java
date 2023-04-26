package creational.prototype;

public abstract class Vehicle {

    // members
    private String brand;

    private String model;

    private String color;

    // getters & setters

    public String getBrand() {
        return brand;
    }
    public String getModel() {
        return model;
    }

    public String getColor() {
        return color;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public void setColor(String color) {
        this.color = color;
    }

    // constructors
    public Vehicle(String brand, String model, String color) {
        this.brand = brand;
        this.model = model;
        this.color = color;
    }

    protected Vehicle(Vehicle vehicle) {
        this.brand = vehicle.brand;
        this.model = vehicle.model;
        this.color = vehicle.color;
    }


    // methods
    public abstract Vehicle clone();

}
