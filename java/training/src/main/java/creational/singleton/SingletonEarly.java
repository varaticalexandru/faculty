package creational.singleton;

// early instantiation
public class SingletonEarly {

    // members (private static)
    private static SingletonEarly instance = new SingletonEarly();

    // constructors (private)
    private SingletonEarly() {}

    // methods (public static)
    public static SingletonEarly getInstance() {
        return instance;
    }

    public void showMessage() {
        System.out.println("Moin moin wie geht's dir ?");
    }
}
