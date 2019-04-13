/*
PROBLEM STATEMENT:-Write a program on template and exception handling in Java: in this assignment multiple
                   templates are to be designed as a pattern and these patterns to be used to take decisions.
*/
import java.util.Scanner;
class p13
{
    public static void main(String[]args)
 {
    int a,b,result;
    
    
     Scanner input=new Scanner(System.in);
     System.out.println("Input two integers");
     
     
     a=input.nextInt();
     b=input.nextInt();
    //try block
      try
      {
         result=a/b;
         System.out.println("Result=" + result);
      }
    //catch block
      catch(ArithmeticException e)
      {
         System.out.println("Exception caught:Division by zero,");
      }
      finally
      {
        System.out.println("Exception Handling");
      }
 }              
}  
