package palindromeInitials;

import java.util.Scanner;

public class InitialsChar {
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter Your Name : ");
        String name = scanner.nextLine();
        scanner.close();
        System.out.println("Initials: "+getInitials(name));
    }
    public static String getInitials(String name){
        StringBuilder initials = new StringBuilder();
        String[] words=name.split(" ");
        for (String word:words){
            if (!word.isEmpty()) {
                initials.append(Character.toUpperCase(word.charAt(0))).append(".");
            }
        }
        return initials.toString();
    }
}
