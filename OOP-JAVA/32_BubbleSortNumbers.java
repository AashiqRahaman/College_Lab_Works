// Write a program to design a class Volume and then find out the volume of a Cube, Cylinder using method overloading.
public class BubbleSortNumbers {
    private int a, b, c, d, e;
    public BubbleSortNumbers() {
        this(0, 0, 0, 0, 0);
    }
    public BubbleSortNumbers(int a, int b, int c, int d, int e) {
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
        this.e = e;
    }
    // Bubble Sort method
    public void sortNumbers() {
        int[] arr = {a, b, c, d, e};
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        a = arr[0];
        b = arr[1];
        c = arr[2];
        d = arr[3];
        e = arr[4];
    }
    public void displayNumbers() {
        System.out.println(a + " " + b + " " + c + " " + d + " " + e);
    }
    public static void main(String[] args) {
        BubbleSortNumbers numbers = new BubbleSortNumbers(34, 12, 56, 7, 89);
        System.out.println("Before Sorting:");
        numbers.displayNumbers();
        numbers.sortNumbers();
        System.out.println("After Sorting:");
        numbers.displayNumbers();
    }
}
