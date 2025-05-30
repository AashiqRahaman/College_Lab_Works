class MyRunnable implements Runnable {
    @Override
    public void run(){
        for(int i = 0; i< 6 ; i++){
        System.out.println(Thread.currentThread().getName() + " Counting -> " + i);
        }   
    }
}


public class MultiThread {
    public static void main(String[] args){
        Thread thread1 = new Thread(new MyRunnable() , "Thread-1");
        Thread thread2 = new Thread(new MyRunnable() , "Thread-2");

        thread1.start();
        thread2.start();
        }
}
