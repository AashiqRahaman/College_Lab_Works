import java.util.Scanner;
public class Swap{
    public static void main(String[] args){
    int num1,num2,temp;
    Scanner sc = new Scanner(System.in);
    System.out.println("enter the 2 two number:");
    num1 = sc.nextInt();
    num2 = sc.nextInt();
    sc.close();
    System.out.println("Numbers Before Swapping , Num1 = :" + num1 + " num2 = "+ num2);
    num1 = num1 + num2;
    num2 = num1 - num2;
    num1 = num1 - num2;
    System.out.println("Numbers After Swapping , Num1 = :" + num1 + " num2 = "+ num2);    
}
}
