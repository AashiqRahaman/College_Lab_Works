public class DivZero {
    public static void main(String[] args) {
        try {
            int numerator = 10;
            int denominator = 0;
            int result = numerator / denominator;
            System.out.println("The result is: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
            System.out.println("Exception message: " + e.getMessage());
        } finally {
            System.out.println("Execution of the try-catch block is complete.");
        }
    }
}
    

