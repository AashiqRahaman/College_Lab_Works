import java.util.ArrayList;
import java.util.List;

public class EqualSubstringFinder {

    public static List<String> findEqualSubstrings(String s) {
        int n = s.length();
        List<String> substrings = new ArrayList<>();

        // Iterate through all starting points
        for (int i = 0; i < n; i++) {
            int count0 = 0, count1 = 0, count2 = 0;

            // Check all substrings starting from index i
            for (int j = i; j < n; j++) {
                if (s.charAt(j) == '0') {
                    count0++;
                } else if (s.charAt(j) == '1') {
                    count1++;
                } else if (s.charAt(j) == '2') {
                    count2++;
                }

                if (count0 == count1 && count1 == count2) {
                    substrings.add(s.substring(i, j + 1));
                }
            }
        }

        return substrings;
    }

    public static void main(String[] args) {
        String str = "102100211";
        List<String> substrings = findEqualSubstrings(str);

        System.out.println("Substrings with equal 0, 1, and 2:");
        for (String substring : substrings) {
            System.out.println(substring);
        }
        System.out.println("So No. of Substrings are  -> " + substrings.size());
    }
}