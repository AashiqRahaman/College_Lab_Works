// 1. Java String Program to Check Anagram Input: str1 = "Listen" str2 = "Silent" Output: Yes An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. 



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
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();

        if (str1.length() != str2.length()) {
            return false;
        }

        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();

        Arrays.sort(charArray1);
        Arrays.sort(charArray2);

        // Compare sorted arrays
        return Arrays.equals(charArray1, charArray2);
    }
}
