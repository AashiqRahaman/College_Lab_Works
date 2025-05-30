package theoryException;

class EvenNumberSquareGenerator implements Runnable {
    public void run() {
        for (int i = 1; i <= 30; i++) {
            int evenNumber = 2 * i;
            int square = evenNumber * evenNumber;
            System.out.println("Even Number: " + evenNumber + ", Square: " + square);
            try {
                Thread.sleep(100); // Adding a small delay to simulate thread execution
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class EvenNumberSquareThread {
    public static void main(String[] args) {
        // Creating a thread
        Thread thread = new Thread(new EvenNumberSquareGenerator());
        thread.start(); // Starting the thread
    }
}

