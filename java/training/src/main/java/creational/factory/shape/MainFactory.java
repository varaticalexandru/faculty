package creational.factory.shape;

public class MainFactory {

    public static void main(String[] args) {

        ShapeFactory factory = new ShapeFactory();

        Shape shape = factory.getInstance("parallelogram");
        shape.draw();
    }
}
