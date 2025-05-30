class Triangle {
    private double side1, side2, side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }
    public double getPerimeter() {
        return side1 + side2 + side3;
    }
}

class Rectangle {
    private double length, width;

    public Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    public double getPerimeter() {
        return 2 * (length + width);
    }
}

class Square {
    private double side;

    public Square(double side) {
        this.side = side;
    }
    public double getPerimeter() {
        return 4 * side;
    }
}

public class Perimeter {
    public static void main(String[] args) {
        // Create instances and calculate perimeters
        Triangle triangle = new Triangle(3, 4, 5);
        System.out.println("Perimeter of Triangle: " + triangle.getPerimeter());

        Rectangle rectangle = new Rectangle(5, 10);
        System.out.println("Perimeter of Rectangle: " + rectangle.getPerimeter());

        Square square = new Square(4);
        System.out.println("Perimeter of Square: " + square.getPerimeter());
    }
}
