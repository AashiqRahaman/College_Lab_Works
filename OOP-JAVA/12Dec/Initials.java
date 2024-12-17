import java.util.Scanner;
public class Initials{
 public static void main (String[] args){
   Scanner scanner = new Scanner(System.in);
   System.out.println("Enter Your Full Name : ");
   String name = scanner.nextLine();
   name= name.toUpperCase();
   scanner.close();
   System.out.println("Initials: "+getInitials(name));
  }
  //  public static String getInitials(String name){
  //   String[] words=name.split("\\s+");
  //   StringBuilder initials = new StringBuilder();
  //   for(String word:words){
  //   initials.append(word.charAt(0)).append(".");
  //   }
  //   return initials.toString().trim();
  //  }
  // }

  public static String getInitials(String name) {
    String[] words = name.split("\\s+");
    StringBuilder initials = new StringBuilder();
    for (int i = 0; i < words.length; i++) {
        initials.append(words[i].charAt(0)); 
        if (i < words.length - 1) 
        { 
            initials.append(".");
        }
    }
    return initials.toString();
}
}

