/*
Write a Java program which will demonstrate a concept of Interfaces and packages: In this
assignment design and use of customized interfaces and packages for a specific application
are expected
*/
import subtask.*;
import java.util.*;

interface Exam
{
	public void acceptMarks();
	public void cal();
}
class Student implements Exam
{
	int n;
	public int sum=0;
	public double per;
	int []marks=new int[10];
	
	public void acceptMarks()
	{
		Scanner scan= new Scanner(System.in);
		System.out.println("Enter number of Subjects:");
		n=scan.nextInt();
		System.out.println("Enter Marks:");
		for(int i=0;i<n;i++)
		{
			marks[i]=scan.nextInt();
		}
	}
	
	public void cal()
	{
		for(int i=0;i<n;i++	)
		{
			sum=sum+marks[i];
		}
		per=sum/n;
	}
}

class p12
{
	public static void main(String args[])
	{
		Student s1=new Student();
		StudentInfo s2=new StudentInfo();
		
		s1.acceptMarks();
		s1.cal();
		s2.displayMarks(s1.sum,s1.per);
	}
}
