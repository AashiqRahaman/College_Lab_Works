package theoryException;

public class TestTryCatchByZero {
    public static void main(String[] args) {
        System.out.println("main method started");
        int a = 10, b = 0, c;
        try {
            c = a/b;
            System.out.println(c);
        }catch (Exception e){
            System.out.println("cannot Divide by zero");
        }
        if(b==0){
            throw new ArithmeticException("b is 0");
        }
        System.out.println("main method ended");
    }
}
