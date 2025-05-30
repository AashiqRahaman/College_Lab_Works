public class DivisionByZero {
    public static void main(String[] args) {
        try {

            int numerator = 18;
            int denominator = 8;
            int result = numerator / denominator;

            System.out.println("Result:" + result);

        } catch (ArithmeticException e) {

            System.out.println("Exception: Division by zero is not allowed.");
        }
    }

}