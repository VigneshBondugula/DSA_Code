/*BUBBLE SORT*/
#include<stdio.h>
void bubblesort(long long int array[])		    //Defining a function named bubble sort which takes an unsorted array and prints sorted array 
{
	int i,j,comparisions=0,swaps=0;             //Declaring variables which are integers 
	long long int temp;                         //Declaring temporary variable which stores an array element during swap
	for(i=0;i<19;i++)
	{
		for(j=0;j<19-i;j++)                  //Iteration over the array
		{
			if(array[j]>array[j+1])      //If the element selected is greater than next element then push the selected element forward      
			{
				temp=array[j];       //Storing into temporary variable.It is a step in swapping 
				array[j]=array[j+1]; //Swapping
				array[j+1]=temp;     //Swapping
				swaps+=1;            //Incrementing the number of swaps since we swapped two elements 
			}
			comparisions+=1;             //Incrementing comparisions since we compared to elements
		} 
	}
	for(i=0;i<20;i++)
		{
			printf("%lld ",array[i]); //Printing the elements of the sorted array 
		}
	printf("\n%d %d",swaps,comparisions);	  //Printing the number of swaps and comparisions		
}
int main()
{
	long long int array[20];                  //Declaring the array as long long int
	int i;	                                  //Declaring variable which is integer   
	for(i=0;i<20;i++)
		{	
			scanf("%lld,",&array[i]); //Taking the inputs of elements of array
		}	
	bubblesort(array);                        //Calling the bubblesort function to sort the array inputed 
}

