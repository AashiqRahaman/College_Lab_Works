/* Java Oops assignment 16/01/2025
 * 2.Create a Thread using runnable interface.
 */

class MyRunnable implements Runnable {
    @Override
    public void run() {
        for (int i = 1; i <= 10; i++) {
            System.out.println(Thread.currentThread().getName() + " - Count: " + i);
            try {
                Thread.sleep(500); // Simulate work
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted.");
            }
        }
    }
}

public class ThreadDemo {
    public static void main(String[] args) {
        Thread thread = new Thread(new MyRunnable(), "MyThread");
        thread.start();
    }
}
