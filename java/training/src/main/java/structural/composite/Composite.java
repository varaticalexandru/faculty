package structural.composite;

import java.util.ArrayList;
import java.util.List;

public class Composite implements Component {

    // members
    String name;
    List<Component> components = new ArrayList<>();


    // constructors
    public Composite(String name) {
        this.name = name;
    }

    // methods
    public void addComponent(Component c) {
        components.add(c);
    }

    @Override
    public void showPrice() {
        System.out.println(name);
        for (Component c: components) {
            c.showPrice();
        }
    }
}
