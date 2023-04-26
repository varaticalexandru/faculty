package creational.factory.os;

public class OSFactory {
    public OS getInstance(String str) {

        if (str.compareTo("open") == 0)
            return new Android();
        else if (str.compareTo("closed") == 0)
            return new IOS();
        else if (str.compareTo("old") == 0)
            return new Windows();
        else
            return null;
    }
}
