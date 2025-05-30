interface GeoAnalyzer {
    double PI = 3.14159;
    double perimeter();
}
class Circle implements GeoAnalyzer {
    private double radius;
    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    public double perimeter() {
        return 2 * PI * radius;
    }
}
class Rectangle implements GeoAnalyzer {
    private double length, breadth;
    public Rectangle(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }
    @Override
    public double perimeter() {
        return 2 * (length + breadth);
    }
}
public class Geo_If_OR
 {
    public static void main(String[] args) {
        GeoAnalyzer circle = new Circle(4.5);
        GeoAnalyzer rectangle = new Rectangle(5, 7); // Runtime polymorphism

        System.out.println("Perimeter of Circle: " + circle.perimeter());
        System.out.println("Perimeter of Rectangle: " + rectangle.perimeter());
    }
}
