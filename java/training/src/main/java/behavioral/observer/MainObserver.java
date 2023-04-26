package behavioral.observer;

public class MainObserver {

    public static void main(String[] args) {

        Channel channel = new Channel();

        Subscriber s1 = new Subscriber("Sanya");
        Subscriber s2 = new Subscriber("Vanya");
        Subscriber s3 = new Subscriber("Danya");
        Subscriber s4 = new Subscriber("Xanya");

        s1.subscribeChannel(channel);
        s2.subscribeChannel(channel);
        s3.subscribeChannel(channel);
        s4.subscribeChannel(channel);

        channel.uploadVideo("Good morning, Vietnam !");
    }
}
