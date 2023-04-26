package behavioral.observer;

public class Subscriber implements Observer {

    // members
    private String name;
    private Channel channel = new Channel();


    // constructors
    public Subscriber(String name) {
        this.name = name;
    }


    // getters & setters
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Channel getChannel() {
        return channel;
    }

    public void setChannel(Channel channel) {
        this.channel = channel;
    }



    // methods
    @Override
    public void update(String title) {
        System.out.println(
                "Hey, " + this.name + ", new video uploaded: " + title
        );
    }

    @Override
    public void subscribeChannel(Channel channel) {
        this.channel = channel;
        channel.subscribe(this);
    }
}
