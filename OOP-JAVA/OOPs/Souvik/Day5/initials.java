import java.util.Scanner;

public class initials{

    public static String getInitials(String fullName) {
        // Split the full name into words
        fullName = fullName.toLowerCase();
        String[] name = fullName.split(" ");
        String initials = "";

        // Iterate over each word to extract the first character
        for (String letter : name) {
            if (!letter.isEmpty()) {
                initials = initials + letter.charAt(0) + ".";
            }
        }
        // Remove the trailing space and period
        return initials.toString().toUpperCase();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter your name..");
        String fullName = sc.nextLine();

        System.out.println("Initials: " + getInitials(fullName));
        sc.close();
    }
}
