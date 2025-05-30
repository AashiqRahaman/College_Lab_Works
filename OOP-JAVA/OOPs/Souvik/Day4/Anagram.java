import java.util.Arrays;

public class Anagram {
    public static boolean isAnagram(String str1, String str2) {
        // Convert strings to lowercase
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        // Check if both strings have the same length
        if (str1.length() != str2.length()) {
            return false;
        }

        // if length's same Convert strings to character arrays
        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();

        // Sort the character arrays by their ASCII value
        Arrays.sort(charArray1);
        Arrays.sort(charArray2);

        // Compare the sorted character arrays
        return Arrays.equals(charArray1,charArray2);
    }

    public static void main(String[] args) {
        System.out.println(isAnagram("Listen", "Silent")); 
        System.out.println(isAnagram("Hello", "World"));
        System.out.println(isAnagram("Magic", "Gamic"));
        System.out.println(isAnagram("Flower", "Wolfer"));
    }
}

