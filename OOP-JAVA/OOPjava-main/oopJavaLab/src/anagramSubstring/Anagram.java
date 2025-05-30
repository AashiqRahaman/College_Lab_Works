package anagramSubstring;

import java.util.Arrays;

public class Anagram{
    public static void main(String[] args) {
        String str1 = "Listen";
        String str2 = "Silent";
        String str3 = "Silend";

        boolean isAnagram = checkAnagram(str1, str2);
        if (isAnagram) {
            System.out.println("Yes, the strings are anagrams.");
        } else {
            System.out.println("No, the strings are not anagrams.");
        }
        boolean isAnagram2 = checkAnagram(str1, str3);
        if (isAnagram2) {
            System.out.println("Yes, the strings are anagrams.");
        } else {
            System.out.println("No, the strings are not anagrams.");
        }
    }

    public static boolean checkAnagram(String str1, String str2) {

        str1 = str1.replaceAll("\\s", "").toLowerCase();
        str2 = str2.replaceAll("\\s", "").toLowerCase();


        if (str1.length() != str2.length()) {
            return false;
        }

        char[] charArray1 = str1.toCharArray();
        char[] charArray2 = str2.toCharArray();


        Arrays.sort(charArray1);
        Arrays.sort(charArray2);

        return Arrays.equals(charArray1, charArray2);
    }
}