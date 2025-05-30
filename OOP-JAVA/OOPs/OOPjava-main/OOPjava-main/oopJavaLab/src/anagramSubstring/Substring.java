package anagramSubstring;

public class Substring {
    public static void main(String[] args) {
        String str = "102100211";

        findAllEqual012Substrings(str);
    }

    public static void findAllEqual012Substrings(String str) {
        int n = str.length();
        int totalCount = 0;

        System.out.println("Substrings with equal 0, 1, and 2:");


        for (int i = 0; i < n; i++) {
            int count0 = 0, count1 = 0, count2 = 0;

            for (int j = i; j < n; j++) {
                char ch = str.charAt(j);


                if (ch == '0') {
                    count0++;
                } else if (ch == '1') {
                    count1++;
                } else if (ch == '2') {
                    count2++;
                }


                if (count0 == count1 && count1 == count2) {
                    System.out.println(str.substring(i, j + 1));
                    totalCount++;
                }
            }
        }

        System.out.println("Total count: " + totalCount);
    }
}
