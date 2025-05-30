/* Java Oops assignment 16/01/2025
 * write a java program to throw division by zero exception and catch it.
 */

public class DivisionByZeroDemo {
    public static void main(String[] args) {
        try {
            int num = 10;
            int denom = 0;
            int result = num / denom;
            System.out.println("Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Exception caught: Division by zero is not allowed.");
        }
    }
}
