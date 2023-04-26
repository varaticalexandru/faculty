package creational.builder.burger;

public class Burger {

    // members
    private String bun;
    private boolean ketchup;
    private boolean mayo;
    private boolean salad;

    // constructor
    public Burger(String bun, boolean ketchup, boolean mayo, boolean salad) {
        this.bun = bun;
        this.ketchup = ketchup;
        this.mayo = mayo;
        this.salad = salad;
    }

    // methods
    @Override
    public String toString() {
        return "Burger{" +
                "bun='" + bun + '\'' +
                ", ketchup=" + ketchup +
                ", mayo=" + mayo +
                ", salad=" + salad +
                '}';
    }
}
