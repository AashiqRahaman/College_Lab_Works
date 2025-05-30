public class Question {
    public static void main(String[] args) {
        try {
            int a = 5 / 0; 
        } catch (Exception e) {
            // This catch block will not be executed 
            // as ArithmeticException is handled specifically below
        } catch (ArithmeticException a) {
            System.out.println("Cannot divide by 0");
        }
        System.out.println("Hello World"); 
    }
}