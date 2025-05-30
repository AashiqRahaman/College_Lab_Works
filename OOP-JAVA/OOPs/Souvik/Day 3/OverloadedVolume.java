class Volume {
    //Cube
    public double calculateVolume(double side) {
        return side * side * side; // Volume of cube = side³
    }

    //Cylinder
    public double calculateVolume(double radius, double height) {
        return Math.PI * radius * radius * height; // Volume of cylinder = πr²h
    }
}
public class OverloadedVolume{ 
    public static void main(String[] args) {
        Volume vol = new Volume();

        // Volume of a cube
        double cubeVolume = vol.calculateVolume(5.0);
        System.out.println("Volume of the Cube is: " + cubeVolume);

        // Volume of a cylinder
        double cylinderVolume = vol.calculateVolume(3.0, 7.0);
        System.out.println("Volume of the Cylinder is: " + cylinderVolume);
    }
}