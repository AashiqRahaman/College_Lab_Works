package theoryException;

public class ThrowThrows {
    void div(int a, int b){
        if (b == 0){
            throw new ArithmeticException("cannot divide by zero");
        }else{
            int c = a/b;
            System.out.println(c);
        }
    }

    public static void main(String[] args){
        ThrowThrows t = new ThrowThrows();
        t.div(20,0);
    }
}
