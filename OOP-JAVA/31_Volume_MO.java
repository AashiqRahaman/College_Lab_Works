// Write a program to design a class Volume and then find out the volume of a Cube, Cylinder using method overloading.

class Volume {
    public double calculateVolume(double side) {
        return side * side * side;
    }
    public double calculateVolume(double radius, double height) {
        return Math.PI * radius * radius * height;
    }
    public static void main(String[] args) {
        Volume volume = new Volume();
        double cubeVolume = volume.calculateVolume(5.0);
        System.out.println("Volume of Cube: " + cubeVolume);
        double cylinderVolume = volume.calculateVolume(3.0, 7.0);
        System.out.println("Volume of Cylinder: " + cylinderVolume);
    }
}
