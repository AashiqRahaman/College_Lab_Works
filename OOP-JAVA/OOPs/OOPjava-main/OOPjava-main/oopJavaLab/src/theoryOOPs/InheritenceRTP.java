package theoryOOPs;

// For Inheritance -> extends

class Shape{
    public void area(){
        System.out.println("Display Area");
    }
}

class Triangle extends Shape{
    public void area(int l, int h){
        System.out.println(1/2 * l * h);
    }
}

class EquilateralTriangle extends Triangle{
    public void perimeter(int length){
        System.out.println(length*3);
    }
}

class Circle extends Shape{
    public void area(int radius){
        System.out.println((3.14)*radius*radius);
    }
}

public class InheritenceRTP {
    public static void main(String[] args) {

    }
}
