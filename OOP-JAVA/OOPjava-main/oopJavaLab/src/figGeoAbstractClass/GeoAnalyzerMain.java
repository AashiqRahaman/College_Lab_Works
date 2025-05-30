package figGeoAbstractClass;

interface GeoAnalyzer {
    double PI = 3.14159;

    // Method to compute perimeter
    double perimeter();
}

class CircleImp implements GeoAnalyzer {
    private double radius;

    // Constructor
    public CircleImp(double radius) {
        this.radius = radius;
    }

    // Overridden perimeter method
    @Override
    public double perimeter() {
        return 2 * PI * radius;
    }
}

class RectangleImp implements GeoAnalyzer {
    private double length, breadth;

    // Constructor
    public RectangleImp(double length, double breadth) {
        this.length = length;
        this.breadth = breadth;
    }

    // Overridden perimeter method
    @Override
    public double perimeter() {
        return 2 * (length + breadth);
    }
}

public class GeoAnalyzerMain {
    public static void main(String[] args) {
        GeoAnalyzer circle = new CircleImp(4.5); // Runtime polymorphism
        GeoAnalyzer rectangle = new RectangleImp(5, 7); // Runtime polymorphism

        System.out.println("Perimeter of Circle: " + circle.perimeter());
        System.out.println("Perimeter of Rectangle: " + rectangle.perimeter());
    }
}
