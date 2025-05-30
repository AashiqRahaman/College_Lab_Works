class Triangle {
    double side1, side2, side3;
    Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }
    double calculatePerimeter() {
        System.out.println("Sides of Triangle are S1 = "+side1+", S2 = "+side2+", S3 = "+side3);
        return side1 + side2 + side3;
    }
}

class Rectangle {
    double length, width;
    Rectangle(double length, double width) {
        this.length = length;
        this.width = width;
    }
    double calculatePerimeter() {
        System.out.println("Rectangle's Length = "+length+", Width= "+width);
        return 2 * (length + width);
    }
}
class Square {
    double side;
    Square(double side) {
        this.side = side;
    }
    double calculatePerimeter() {
        System.out.println("Triangle's Side = "+side);
        return 4 * side;
    }
}


public class Main {
    public static void main(String[] args) {
        Triangle triangle = new Triangle(3, 4, 5);
        Rectangle rectangle = new Rectangle(6, 4);
        Square square = new Square(5);

        System.out.println("Perimeter of Triangle: " + triangle.calculatePerimeter()+"\n");
        System.out.println("Perimeter of Rectangle: " + rectangle.calculatePerimeter()+"\n");
        System.out.println("Perimeter of Square: " + square.calculatePerimeter()+"\n");
    }
}
