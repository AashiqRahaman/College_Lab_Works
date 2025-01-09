// Problem1: Given an array of integers, find the maximum sum of a subarray with a fixed window size of 3 (i.e., window size=3). Sample array: {2, 1, 5, 0, 1, 2, 3, 0, 2, 1}.
// package OOP-JAVA.9Jan;

class SubarrayCalculator {
    private int[] array;

    // Constructor
    public SubarrayCalculator(int[] array) {
        this.array = array;
    }

    // Method to find the maximum sum of a subarray with a fixed window size
    public int findMaxSum(int windowSize) {
        if (array.length < windowSize) {
            throw new IllegalArgumentException("Array size is smaller than window size.");
        }

        int maxSum = 0, currentSum = 0;

        // Calculate the sum of the first window
        for (int i = 0; i < windowSize; i++) {
            currentSum += array[i];
        }
        maxSum = currentSum;

        // Slide the window through the array
        for (int i = windowSize; i < array.length; i++) {
            currentSum = currentSum - array[i - windowSize] + array[i];
            maxSum = Math.max(maxSum, currentSum);
        }
        return maxSum;
    }
}

public class Problem1 {
    public static void main(String[] args) {
        int[] array = {2, 1, 5, 0, 1, 2, 3, 0, 2, 1};
        SubarrayCalculator calculator = new SubarrayCalculator(array);
        int windowSize = 3;

        System.out.println("Maximum sum of subarray with window size " + windowSize + ": " + calculator.findMaxSum(windowSize));
    }
}
