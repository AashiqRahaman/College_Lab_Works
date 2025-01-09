

public class Problem2
 {
    public static int findLongestUniqueSubstring(String input) {
        int maxLength = 0; // Store the length of the longest substring
        int start = 0;     // Pointer for the start of the window
        int[] charIndex = new int[256]; // Array to track the last seen position of characters

        // Initialize character positions to -1
        for (int i = 0; i < 256; i++) {
            charIndex[i] = -1;
        }

        // Iterate through the string
        for (int end = 0; end < input.length(); end++) {
            char currentChar = input.charAt(end);

            // Update the start of the window if the character is repeated
            if (charIndex[currentChar] >= start) {
                start = charIndex[currentChar] + 1;
            }

            // Update the character's last seen position
            charIndex[currentChar] = end;

            // Update the maximum length
            maxLength = Math.max(maxLength, end - start + 1);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        String input = "abcbbcbbkhlkkmnhhgbabfds";
        System.out.println("Length of the longest substring without repeating characters: " + findLongestUniqueSubstring(input));
    }
}
