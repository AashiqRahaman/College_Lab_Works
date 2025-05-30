package figGeoAbstractClass;

// 1. Create a class Figure with method area and two member variables. Class Rectangle and class Triangle invoke
// super class constructor and compute their respective area. (using super keyword, method overriding, and run-
// time polymorphism).


class Figure {
    double dimension1, dimension2;

    // Constructor
    public Figure(double dimension1, double dimension2) {
        this.dimension1 = dimension1;
        this.dimension2 = dimension2;
    }

    // Method to compute area (default implementation)
    public double area() {
        return 0;
    }
}

class Rectangle extends Figure {
    // Constructor
    public Rectangle(double length, double breadth) {
        super(length, breadth);
    }

    // Overridden method to compute area
    @Override
    public double area() {
        return dimension1 * dimension2;
    }
}

class Triangle extends Figure {
    // Constructor
    public Triangle(double base, double height) {
        super(base, height);
    }

    // Overridden method to compute area
    @Override
    public double area() {
        return 0.5 * dimension1 * dimension2;
    }
}

public class FigureMain {
    public static void main(String[] args) {
        Figure rectangle = new Rectangle(5, 7); // Runtime polymorphism
        Figure triangle = new Triangle(6, 8);  // Runtime polymorphism

        System.out.println("Area of Rectangle: " + rectangle.area());
        System.out.println("Area of Triangle: " + triangle.area());
    }
}
