import java.util.Scanner;
public class palin {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter a string to Check Wheather the stringis palindrom or not:  ");
        String input= scanner.nextLine();
        
        if (isPalindrome(input)) {
            System.out.println("Input String:\""+input+"\" is Palindrome");
        } else {
            System.out.println("Input String: \""+input+"\" Is Not Palindrome");
        }
    }
    public static boolean isPalindrome(String str) {
        str=str.toLowerCase();
        int left=0;
        int right=str.length()-1;
        while (left<right){
            if (str.charAt(left)!=str.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }            
}

