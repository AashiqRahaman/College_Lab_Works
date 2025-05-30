/*Create a class Figure with method area and two member variables. Class Rectangle and class Triangle invoke
super class constructor and compute their respective area. (using super keyword, method overriding, and 0run-
time polymorphism).
*/

class Figure {
    double dimension1, dimension2;

    Figure(double d1, double d2) {
        this.dimension1 = d1;
        this.dimension2 = d2;
    }

    double area() {
        return 0; // To be overridden
    }
}

class Rectangle extends Figure {
    Rectangle(double length, double breadth) {
        super(length, breadth);
    }

    @Override
    double area() {
        return dimension1 * dimension2; // Rectangle area: length * breadth
    }
}

class Triangle extends Figure {
    Triangle(double base, double height) {
        super(base, height);
    }

    @Override
    double area() {
        return 0.5 * dimension1 * dimension2; // Triangle area: 0.5 * base * height
    }
}

public class TestFigure {
    public static void main(String[] args) {
        Figure rect = new Rectangle(4, 5);
        Figure tri = new Triangle(6, 9);

        System.out.println("Rectangle Area: " + rect.area());
        System.out.println("Triangle Area: " + tri.area());
    }
}