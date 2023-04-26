package creational.prototype;

public class MainPrototype {

    public static void main(String[] args) {

        Bus b = new Bus("Volvo", "123", "blue", 4);
        Bus b_1 = b.clone();

        b.setWheels(8);
        System.out.println(b_1.getWheels());
    }
}
