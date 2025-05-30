package theoryOOPs;

interface AnimalInterface{
    public void walk();
    public void eat();
}
interface Hervivores{

}
class HorseIF implements AnimalInterface, Hervivores{
    public void walk(){
        System.out.println("Walks on 4 legs");
    }
    public void eat(){
        System.out.println("Horse eat Grass");
    }
}

public class InterFACE {
    public static void main(String[] args) {
        HorseIF horse = new HorseIF();
        horse.walk();
        horse.eat();
    }
}
