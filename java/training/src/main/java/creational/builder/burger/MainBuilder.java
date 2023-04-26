package creational.builder.burger;

public class MainBuilder {

    public static void main(String[] args) {

        Burger burger = new BurgerBuilder()
                .setBun("wheat")
                .setKetchup(true)
                .getBurger();

        System.out.printf(burger.toString());
    }
}
