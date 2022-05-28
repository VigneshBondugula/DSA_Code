/*SELECTION SORT*/
#include<stdio.h>
void selectionsort(long long int array[])             //Declaring a function named selectionsort which sorts the given unsorted array
{
	int i,j,minimum,comparisions=0,swaps=0;       //Declaring the variables which are integers  
	long long int temp;                           //Declaring the temporary long long int variable which stores an array element when swapping
	for(i=0;i<19;i++)                             //Iterating over the array and selecting an element      
	{
		minimum=i;                            //Giving the minimum value as selecting element index
		for(j=i+1;j<20;j++)                   //Iterating the array elements after the selected element   
		{
			if(array[j]<array[minimum])   //If any element is less than the minimum element then make that element's index as minimum
			{
				minimum=j;		
			}
			comparisions+=1;              //Increment the number of comparisions by 1 as we compared two elements
		}
		temp=array[minimum];                  //Storing the minimum element in the temporary variable which is used in the swapping process
		array[minimum]=array[i];              //Swapping the minimum element and the selected element
		array[i]=temp;                        //Swapping 
		swaps+=1;                             //Incrementing the number of swaps by 1 as we swapped two elements
	}
	for(i=0;i<20;i++)                             
		{
			printf("%lld ",array[i]);     //Printing the elements of sorted array 
		}
	printf("\n%d %d",swaps,comparisions);	      //Printing number of swaps and number of comparisions		
}
int main()
{
	long long int array[20];                      //Declaring the array as long long int  
	int i;	                                      //Declaring the variables as integers   
	for(i=0;i<20;i++)
		{	
			scanf("%lld,",&array[i]);     //Taking the inputs of array which is to be sorted 
		}	
	selectionsort(array);                         //Calling the selectionsort function to sort the array inputed
}
