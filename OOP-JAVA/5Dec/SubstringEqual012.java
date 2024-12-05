import java.util.HashMap;

public class SubstringEqual012 {
    public static void main(String[] args) {
        String str = "102100211";
        System.out.println("Number of substrings with equal 0, 1, and 2: " + countEqual012Substrings(str));
    }

    public static int countEqual012Substrings(String str) {
        int count = 0;

        // HashMap to store (difference of counts) and their frequencies
        HashMap<String, Integer> map = new HashMap<>();
        int count0 = 0, count1 = 0, count2 = 0;

        // Add initial state to the map
        map.put("0#0", 1);

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);

            // Update counts for 0, 1, and 2
            if (ch == '0') count0++;
            else if (ch == '1') count1++;
            else if (ch == '2') count2++;

            // Create the key as the differences
            String key = (count1 - count0) + "#" + (count2 - count1);

            // If the key exists, add its frequency to count
            count += map.getOrDefault(key, 0);

            // Update the map with the new key or increment its frequency
            map.put(key, map.getOrDefault(key, 0) + 1);
        }

        return count;
    }
}

