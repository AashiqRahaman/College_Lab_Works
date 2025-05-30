package lab3;

//write a java class which consists of 5 integers data. Overload constructor to initialize these integers data members. Provide a method which sorts those integers data members using bubble sort.

public class IntegerSorter{
    int a1, a2, a3, a4, a5;


    public IntegerSorter(){
        this.a1 = 0;
        this.a2 = 0;
        this.a3 = 0;
        this.a4 = 0;
        this.a5 = 0;

    }

    IntegerSorter(int b1, int b2, int b3, int b4, int b5) {
        // Parameterized constructor to initialize values
        a1 = b1;
        a2 = b2;
        a3 = b3;
        a4 = b4;
        a5 = b5;
    }

    void sort() {
        int[] bub = {a1, a2, a3, a4, a5};  // Initialize the array with values of a1, a2, a3, a4, a5
        int temp;

        // Bubble sort algorithm to sort the array
        for (int i = 0; i < bub.length - 1; i++) {
            for (int j = 0; j < bub.length - 1 - i; j++) {
                if (bub[j] > bub[j + 1]) {
                    temp = bub[j];
                    bub[j] = bub[j + 1];
                    bub[j + 1] = temp;
                }
            }
        }

        // Print the sorted array
        for (int j = 0; j < bub.length; j++) {
            System.out.println(bub[j]);
        }
    }


    public static void main(String arg[]) {

        IntegerSorter ob2 = new IntegerSorter(6, 3, 7, 8, 2);  // Parameterized constructor
        ob2.sort();  // Sort and print values of ob2
    }
}
