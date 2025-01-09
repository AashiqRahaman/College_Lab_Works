abstract class Geometry {
    final double PI = 3.14159;

    // Abstract method for area
    public abstract double area();
}

class Circle extends Geometry {
    private double radius;

    // Constructor
    public Circle(double radius) {
        this.radius = radius;
    }

    // Overridden area method
    @Override
    public double area() {
        return PI * radius * radius;
    }
}

class Rectangle extends Geometry {
    private double length, breadth;

    // Constructor
    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Overridden area method
    @Override
    public double area() {
        return length * breadth;
    }
}

public class Main2 {
    public static void main(String[] args) {
        Geometry circle = new Circle(4.5); // Runtime polymorphism
        Geometry rectangle = new Rectangle(5, 7); // Runtime polymorphism

        System.out.println("Area of Circle: " + circle.area());
        System.out.println("Area of Rectangle: " + rectangle.area());
    }
}
