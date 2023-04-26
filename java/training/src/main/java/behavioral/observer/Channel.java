package behavioral.observer;

import java.util.ArrayList;
import java.util.List;

public class Channel implements Subject {

    // members

    List<Subscriber> subscribers = new ArrayList<>();
    private String title;


    // getters & setters
    public List<Subscriber> getSubscribers() {
        return subscribers;
    }

    public void setSubscribers(List<Subscriber> subscribers) {
        this.subscribers = subscribers;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }



    // methods
    @Override
    public void subscribe(Subscriber sub) {
        subscribers.add(sub);
    }

    @Override
    public void unsubscribe(Subscriber sub) {
        subscribers.remove(sub);
    }

    @Override
    public void notifySubscribers() {
        for (Subscriber sub: subscribers) {
            sub.update(this.title);
        }
    }

    @Override
    public void uploadVideo(String title) {
        this.title = title;
        this.notifySubscribers();
    }
}
