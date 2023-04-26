package behavioral.observer;

public interface Subject {
    // methods
    void subscribe(Subscriber sub);

    void unsubscribe(Subscriber sub);

    void notifySubscribers();

    void uploadVideo(String title);
}
