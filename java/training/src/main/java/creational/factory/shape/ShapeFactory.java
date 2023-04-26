package creational.factory.shape;

public class ShapeFactory {

    public Shape getInstance(String str) {

        if (str.compareTo("equilateral") == 0)
            return new Triangle();
        else if (str.compareTo("round") == 0)
            return new Circle();
        else if (str.compareTo("parallelogram") == 0)
            return new Rectangle();
        else
            return null;
    }
}
