/*QUICK SORT*/
#include<stdio.h>
int flag=0,f=0;                                            //Delaring flag and f as global variable as they are used in two different arrays
int partition(long long int array[],int a,int b);          //Declaring partition function which is called in quicksort function 
void quicksort(long long int array[],int a,int b)          //Defining quicksort function which takes an array and sorts it
{
	int c;                                             //Declaring integer variables  
	if(b>a)                                       
	{
		c=partition(array,a,b);                    //Storing the pivot value(p) returned by partition function which is further used in the function 
		quicksort(array,a,c-1);                    //Calling a quicksort function(recursion)
		quicksort(array,c+1,b);                    //Calling a quicksort function(recursion)
	}
}
int partition(long long int array[],int a,int b)           //Defining the partition function which fixes place of the last element(pivot)
{	
	long long int pivot,temp;                          //Defining pivot and temp as long long int
	int j,p;                                           //Defining integer variables
	pivot=array[b];                                    //Fixing the last element of selected range as pivot
	p=a;                                                  
	for(j=a;j<=b-1;j++)
	{
		if(array[j]<pivot)                         //If the selected element is less than the pivot then it should be swapped to p position
		{
			temp=array[p];                     //swapping
			array[p]=array[j];                 //swapping 
			array[j]=temp;                     //swapping
			p++;                               //Incrementing the p value
		}
	}
	array[b]=array[p];                                 //swapping 
	array[p]=pivot;                                    //Swapping to place the pivot at it's position where the elements left to it are less than pivot and right are greater than the pivot   
	if(flag==0)
	{
		f=p;                                       //Storing the final position of first pivot  
		flag=1;
	}
	return p;                                          //Returning the value of pivot so the function continues recursion   
}
int main(void)
{
	int i,n;                                           //Declaring integer varaibles
	scanf("%d",&n);                                    //Taking the input of number of elements in the array     
	long long int array[n];
	for(i=0;i<n;i++)
		{	
			scanf("%lld,",&array[i]);          //Taking the input of values in arrray which is to be sorted   
		}	
	quicksort(array,0,n-1);                            //Calling the quicksort function to sort the given array  
	for(i=0;i<n;i++)
		{
			printf("%lld ",array[i]);          //Printing the lements of the sorted array   
		}	
	printf("\n%d",f);	                           //Printing the final position of firstv pivot
}
