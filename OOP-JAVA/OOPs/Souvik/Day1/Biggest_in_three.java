import java.util.Scanner;
class Big3 {
    int num1;
    int num2;
    int num3;
    
    int printresult(){
        int biggest = (num1 > num2)? ((num1 > num3)? num1 : num3 ): ((num2 > num3)? num2 : num3 );
        return biggest;
    }
}

public class Biggest_in_three{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Big3 solve = new Big3();
        System.out.println("Now Enter the Nunbers 1 by 1");
        solve.num1 = sc.nextInt();
        solve.num2 = sc.nextInt();
        solve.num3 = sc.nextInt();
        sc.close();

        System.out.println("So the Biggest Number is :" + solve.printresult());
    }
}
