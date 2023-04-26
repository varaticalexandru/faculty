package creational.singleton;

// lazy instantiation
public class SingletonLazy {

    // members (private)
    static SingletonLazy instance;

    // constructors (private)
    private SingletonLazy() {};

    // methods  (public)
    public static SingletonLazy getInstance() {
        return
                (instance == null)
                    ? new SingletonLazy()
                    : instance;
    }

    public void showMessage() {
        System.out.println("Moin moin wie geht's dir ?");
    }
}

