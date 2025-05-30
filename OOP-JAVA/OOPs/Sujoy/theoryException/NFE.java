package theoryException;

public class NFE { // NumberFormatException
    public static void main(String[] args) {
        String str = "shubham";
        try {
            int a = Integer.parseInt(str);
            System.out.println(a);
        }catch (NumberFormatException n){
            System.out.println("String [" + str + "] cannot be converted to Integer");
        }
    }
}
