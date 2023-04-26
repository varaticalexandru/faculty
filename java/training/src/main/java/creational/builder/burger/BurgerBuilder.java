package creational.builder.burger;

public class BurgerBuilder {
    // members
    private String bun;
    private boolean ketchup;
    private boolean mayo;
    private boolean salad;

    // setters
    public BurgerBuilder setBun(String bun) {
        this.bun = bun;
        return this;
    }

    public BurgerBuilder setKetchup(boolean ketchup) {
        this.ketchup = ketchup;
        return this;
    }

    public BurgerBuilder setMayo(boolean mayo) {
        this.mayo = mayo;
        return this;
    }

    public BurgerBuilder setSalad(boolean salad) {
        this.salad = salad;
        return this;
    }

    // methods
    public Burger getBurger() {
        return new Burger(bun, ketchup, mayo, salad);
    }

}
