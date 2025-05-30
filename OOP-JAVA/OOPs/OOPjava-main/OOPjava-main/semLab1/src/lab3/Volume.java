package lab3;
// finding volume of cube and cylinder using method overloading
public class Volume {
    public Volume(){};

    public double volume(int length){
        return length * length * length;
    }

    public double volume(int height, int radius){
        return Math.PI * radius * radius * height;
    }

    public static void main(String[] args) {
        Volume box = new Volume();
        double cubeVol = box.volume(7);
        System.out.println("Volume of Cube is : " + cubeVol);

        double cylinderVol = box.volume(20, 7);
        System.out.println("Cylinder Volume is : " + cylinderVol);
    }
}
