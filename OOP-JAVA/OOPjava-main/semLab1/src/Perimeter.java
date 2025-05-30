import java.util.Scanner;
// Class for Triangle
class Triangle {
    double side1, side2, side3;

    // Parameterized constructor for Triangle
    Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    // Method to calculate perimeter
    double calculatePerimeter() {
        return side1 + side2 + side3;
    }
}

// Class for Rectangle
class Rectangle {
    double length, width;

    // Parameterized constructor for Rectangle
    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }

    // Method to calculate perimeter
    double calculatePerimeter() {
        return 2 * (length + width);
    }
}

// Class for Square
class Square {
    double side;

    // Parameterized constructor for Square
    Square(double side) {
        this.side = side;
    }

    // Method to calculate perimeter
    double calculatePerimeter() {
        return 4 * side;
    }
}

public class Perimeter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input for Triangle
        System.out.print("Enter side 1 of the triangle: ");
        int side1 = scanner.nextInt();
        System.out.print("Enter side 2 of the triangle: ");
        int side2 = scanner.nextInt();
        System.out.print("Enter side 3 of the triangle: ");
        int side3 = scanner.nextInt();
        Triangle triangle = new Triangle(side1, side2, side3);

        // Input for Rectangle
        System.out.print("Enter the length of the rectangle: ");
        int length = scanner.nextInt();
        System.out.print("Enter the breadth of the rectangle: ");
        int breadth = scanner.nextInt();
        Rectangle rectangle = new Rectangle(length, breadth);

        // Input for Square
        System.out.print("Enter the side of the square: ");
        int side = scanner.nextInt();
        Square square = new Square(side);

        // Calculate and display perimeters
        System.out.println("\nPerimeter of Triangle: " + triangle.calculatePerimeter());
        System.out.println("Perimeter of Rectangle: " + rectangle.calculatePerimeter());
        System.out.println("Perimeter of Square: " + square.calculatePerimeter());

        scanner.close();
    }
}