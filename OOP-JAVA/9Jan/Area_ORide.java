// 1. Create a class Figure with method area and two member variables. Class Rectangle and class Triangle invoke super class constructor and compute their respective area. (using super keyword, method overriding, and runtime polymorphism).

class Figure {
    double dimension1, dimension2;
    public Figure(double dimension1, double dimension2) {
        this.dimension1 = dimension1;
        this.dimension2 = dimension2;
    }
    public double area() {
        return 0;
    }
}

class Rectangle extends Figure {
    public Rectangle(double length, double breadth) {
        super(length, breadth);
    }
    @Override
    public double area() {
        return dimension1 * dimension2;
    }
}

class Triangle extends Figure {
    public Triangle(double base, double height) {
        super(base, height);
    }
    @Override
    public double area() {
        return 0.5 * dimension1 * dimension2;
    }
}

public class Area_ORide {
    public static void main(String[] args) {
        Figure rectangle = new Rectangle(5, 7); // Runtime polymorphism
        Figure triangle = new Triangle(6, 8);  // Runtime polymorphism

        System.out.println("Area of Rectangle: " + rectangle.area());
        System.out.println("Area of Triangle: " + triangle.area());
    }
}
