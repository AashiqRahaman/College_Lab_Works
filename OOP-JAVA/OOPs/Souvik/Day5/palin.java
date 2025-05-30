import java.util.Scanner;

public class palin {
    public static boolean ispalin(String str1) {
        // Convert strings to lowercase
        str1 = str1.toLowerCase();

        int start = 0;
        int end = str1.length() - 1;

        while(start < end){
            if(str1.charAt(start) != str1.charAt(end)){
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your String..");
        String text = sc.nextLine();

        if(ispalin(text)){
            System.out.println("The text " + text + " is a Palindrome");
        }else{
            System.out.println("The text " + text + " is not a Palindrome");
        }
            sc.close();
    }
}

