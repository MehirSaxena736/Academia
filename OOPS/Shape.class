// Abstract class with an abstract method
abstract class Shape {
    // Abstract method (must be implemented by subclasses)
    abstract void calculateArea();
}
// Subclass Rectangle extends Shape
class Rectangle extends Shape {
    private double length, width;

    // Constructor
    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Overriding calculateArea method
    @Override
    void calculateArea() {
        double area = length * width;
        System.out.println("Rectangle Area: " + area);
    }
}
// Subclass Circle extends Shape
class Circle extends Shape {
    private double radius;

    // Constructor
    Circle(double radius) {
        this.radius = radius;
    }

    // Overriding calculateArea method
    @Override
    void calculateArea() {
        double area = Math.PI * radius * radius;
        System.out.println("Circle Area: " + area);
    }
}
public class Main {
    public static void main(String[] args) {
        // Creating objects of Rectangle and Circle
        Shape rectangle = new Rectangle(5.0, 3.0);
        Shape circle = new Circle(4.0);

        // Calling calculateArea() method
        rectangle.calculateArea();
        circle.calculateArea();
    }
}
