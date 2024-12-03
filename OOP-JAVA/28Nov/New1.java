import java.util.Arrays;

class IntegerData {
    int[] numbers;

   
    public IntegerData(int a, int b, int c, int d, int e) {
        numbers = new int[] {a, b, c, d, e};
    }


    public void bubbleSort() {
        int n = numbers.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (numbers[j] > numbers[j + 1]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[j + 1];
                    numbers[j + 1] = temp;
                }
            }
        }
    }

    public void printNumbers() {
        System.out.println("After sorting the Sorted Numbers: " + Arrays.toString(numbers));
    }

    public static void main(String[] args) {
        IntegerData data = new IntegerData(23, 5, 78, 2, 45);
        System.out.println("Before Sorting the numers : " + Arrays.toString(data.numbers));
        data.bubbleSort(); 
        data.printNumbers(); 
    }
}
