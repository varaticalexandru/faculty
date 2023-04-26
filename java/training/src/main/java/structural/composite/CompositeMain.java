package structural.composite;

public class CompositeMain {

    public static void main(String[] args) {

        // composites
        Composite pc = new Composite("Computer");
        Composite systemUnit = new Composite("System Unit");
        Composite peripherals = new Composite("Peripherals");
        Composite motherboard = new Composite("Motherboard");

        // leaves
        Component monitor = new Leaf("Monitor", 3000);
        Component mouse = new Leaf("Mouse", 300);
        Component cpu = new Leaf("CPU", 9000);
        Component ram = new Leaf("RAM", 6000);
        Component hdd = new Leaf("HDD", 5000);

        // bindings
        pc.addComponent(systemUnit);
        pc.addComponent(peripherals);

        systemUnit.addComponent(motherboard);
        systemUnit.addComponent(hdd);

        motherboard.addComponent(cpu);
        motherboard.addComponent(ram);

        peripherals.addComponent(mouse);
        peripherals.addComponent(monitor);



        pc.showPrice();


    }
}
