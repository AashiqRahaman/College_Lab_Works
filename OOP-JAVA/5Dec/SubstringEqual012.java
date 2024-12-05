// 2. Program to Extract Substring from a String with Equal 0, 1, and 2. Sample Input: str = “102100211” Output: 5 Explanation: "102" , "021" , "210" , " 021" , "210021" these are combinations can be formed where the occurrence of 0 , 1 and 2 all are equal.
public class SubstringEqual012 {
    public static void main(String[] args) {
        String str = "102100211";
        System.out.println("Number of substrings with equal 0, 1, and 2: " + countEqual012Substrings(str));
    }

    public static int countEqual012Substrings(String str) {
        int n = str.length();
        int count = 0;

        // Iterate through all possible substrings
        for (int i = 0; i < n; i++) {
            int count0 = 0, count1 = 0, count2 = 0;

            for (int j = i; j < n; j++) {
                // Update counts based on the current character
                char ch = str.charAt(j);
                if (ch == '0') count0++;
                else if (ch == '1') count1++;
                else if (ch == '2') count2++;

                // Check if counts are equal
                if (count0 == count1 && count1 == count2) {
                    count++;
                }
            }
        }

        return count;
    }
}
