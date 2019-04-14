/*

Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell data
structure with modularity of programming language.
*/

import java.util.Scanner; 
class shell   
{  
   static void shellsort(int[] arr, int num)    
    {    
	int i, j, k, tmp;    
	for (i = num / 2; i> 0; i = i / 2)    
	{    
			for (j = i; j<num; j++)    
			{    

				tmp=arr[j];

				for(k = j; k>= i && arr[k-i]>tmp; k = k - i)    
					arr[k]=arr[k-i];

				arr[k]=tmp;
				   
			}    
		}    
	}     

	public static void main(String[] args)   
	{    
		Scanner sc = new Scanner(System.in);  

		int k,  num;    
		System.out.print("Enter no. of elements : ");      
		
		num = sc.nextInt();  
		int arr[]= new int[num];

        System.out.println("Enter elements : ");
		for (k =  0 ; k<num; k++)    
		{    
			arr[k]=sc.nextInt();    
		}    
		shellsort(arr, num);    
		System.out.println("\nSorted array is: ");    
		for (k = 0; k<num; k++)    
		System.out.println(arr[k]);    
	}    
}
