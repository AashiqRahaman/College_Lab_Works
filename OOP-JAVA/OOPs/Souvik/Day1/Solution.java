import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class TwoSum {
    public List<int[]> allTwoSums(int[] nums, int target) {
        List<int[]> result = new ArrayList<>();
        
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            for (int j = i + 1; j < nums.length; j++) {
                if (complement == nums[j]) {
                    result.add(new int[] {i, j});
                }
            }
        }
        
        return result;
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of number-array:");
        int size = sc.nextInt();
        int[] nums = new int[size];
        
        System.out.println("Enter the numbers one by one:");
        for (int k = 0; k < size; k++) {
            nums[k] = sc.nextInt();
        }
        
        System.out.println("Enter the target:");
        int target = sc.nextInt();
        sc.close();
        
        TwoSum twoSumFinder = new TwoSum();
        List<int[]> indicesList = twoSumFinder.allTwoSums(nums, target);
        
        if (indicesList.isEmpty()) {
            throw new IllegalArgumentException("No pairs found that add upto target");
        } else {
            System.out.println("The pairs of indices that add up to the target are:");
            for (int[] indices : indicesList) {
                System.out.println("[" + indices[0] + ", " + indices[1] + "]");
            }
        }
        
    }
}
