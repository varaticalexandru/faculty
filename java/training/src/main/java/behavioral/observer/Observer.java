package behavioral.observer;

public interface Observer {
    // methods
    void update(String title);

    void subscribeChannel(Channel channel);
}
