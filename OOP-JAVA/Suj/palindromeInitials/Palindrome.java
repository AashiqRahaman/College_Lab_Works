package palindromeInitials;

import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a string");
        String input = scanner.nextLine();
        scanner.close();
        if(ispalindrome(input)){
            System.out.println(input + " is a palindrome");
        }
        else{
            System.out.println( input + " is not a palindrome");
        }
    }
    public static boolean ispalindrome(String str){
        int left = 0;
        int right = str.length() -1;
        while(left<right){
            if (str.charAt(left)!=str.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
