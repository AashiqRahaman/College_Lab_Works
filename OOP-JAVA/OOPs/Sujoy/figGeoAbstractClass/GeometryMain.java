package figGeoAbstractClass;

abstract class Geometry {
    final double PI = 3.14159;

    // Abstract method for area
    public abstract double area();
}

class CircleAbs extends Geometry {
    private double radius;

    // Constructor
    public CircleAbs(double radius) {
        this.radius = radius;
    }

    // Overridden area method
    @Override
    public double area() {
        return PI * radius * radius;
    }
}

class RectangleAbs extends Geometry {
    private double length, breadth;

    // Constructor
    public RectangleAbs(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Overridden area method
    @Override
    public double area() {
        return length * breadth;
    }
}

public class GeometryMain {
    public static void main(String[] args) {
        Geometry circle = new CircleAbs(4.5); // Runtime polymorphism
        Geometry rectangle = new RectangleAbs(5, 7); // Runtime polymorphism

        System.out.println("Area of Circle: " + circle.area());
        System.out.println("Area of Rectangle: " + rectangle.area());
    }
}
