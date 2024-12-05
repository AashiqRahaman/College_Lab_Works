import java.util.Arrays;

public class AnagramCheck {
    public static void main(String[] args) {
        String str1 = "Listen";
        String str2 = "Silent";

        if (areAnagrams(str1, str2)) {
            System.out.println("Yes, the strings are anagrams.");
        } else {
            System.out.println("No, the strings are not anagrams.");
        }
    }

    public static boolean areAnagrams(String str1, String str2) {
        // Convert strings to lowercase and remove spaces (if needed)
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        // Check if lengths match
        if (str1.length() != str2.length()) {
            return false;
        }

        // Convert to char arrays and sort
        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();

        Arrays.sort(charArray1);
        Arrays.sort(charArray2);

        // Compare sorted arrays
        return Arrays.equals(charArray1, charArray2);
    }
}
