package theoryOOPs;
// Polymorphism
// 1. Function overloading (compileTime)
// 2. Function overriding (runTime) (discussed in inheritance)
class Pen{
    String color;
    String type;

    public void write(){
        System.out.println("Writing Something");
    }

    public void printColor(){
        System.out.println(this.color);
    }
}

class Student{
    String name;
    int age;

    // compile time polymorphism -> fun overloading
    public void printInfo(String name){
        System.out.println(name);
    }
    public void printInfo(int age){
        System.out.println(age);
    }
    public void printInfo(String name, int age){
        System.out.println(name + " " + age);
    }

    Student(){}
    Student(String name, int age){
        this.name = name;
        this.age = age;
    }
    Student(Student s){
        this.name = s.name;
        this.age = s.age;
    }
}

public class TheoryOOP {
    public static void main(String[] args) {
        Student s1 = new Student("aman", 23);
        Student s2 = new Student(s1);
        s2.printInfo(s2.name, s2.age);
    }
}
