package structural.composite;

public class Leaf implements Component {

    // members
    String name;
    int price;


    // constructors
    public Leaf(String name, int price) {
        this.name = name;
        this.price = price;
    }

    // methods
    @Override
    public void showPrice() {
        System.out.println(name + ": " + price);
    }
}
