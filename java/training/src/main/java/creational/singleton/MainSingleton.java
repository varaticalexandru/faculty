package creational.singleton;

public class MainSingleton {

    public static void main(String[] args) {

        SingletonEarly object = SingletonEarly.getInstance();
        object.showMessage();

        SingletonLazy object_ = SingletonLazy.getInstance();
        object_.showMessage();
    }
}
