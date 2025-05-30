package theoryException;

public class TryCatchInterruptException {
    public static void wait1() throws InterruptedException {
        for (int i = 1; i <= 10 ; i++) {
            System.out.println(i);
            Thread.sleep(1000);
        }
    }
    public static void main(String[] args) throws InterruptedException{
        wait1();
    }
}
