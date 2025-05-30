class IntegerData {
    public int[] data;

    // No param constructor
    public IntegerData() {
        System.out.println("No parameters provided");
    }

    // Parameterized constructor to initialize 5 integers
    public IntegerData(int a, int b, int c, int d, int e) {
        this.data = new int[]{a, b, c, d, e};
    }

    public void sortData() {
        int n = data.length;

        // Bubble Sort logic
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (data[j] > data[j + 1]) {
                    // Swap elements
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
}
public class bubbleSort {
    // Main method to test the class
    public static void main(String[] args) {
        // Initialize the object using the parameterized constructor
        IntegerData obj0 = new IntegerData();
        IntegerData obj1 = new IntegerData(64, 34, 25, 12, 22);


        System.out.println("Unsorted array:");
        for (int num : obj1.data) {
            System.out.print(num + " ");
        }

        // Sort the array using Bubble Sort
        obj1.sortData();

        System.out.println("\nSorted array:");
        for (int num : obj1.data) {
            System.out.print(num + " ");
        }
    }
}

