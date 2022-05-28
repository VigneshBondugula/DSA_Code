/*MERGE SORT*/
#include<stdio.h>
int no_of_merges=0;                                                //Declaring a global variable to calculate the number of times merge function is called
void merge(long long int array[],int a,int mid,int b);             //Declaring the merge function which is called in mergesort function   
void mergesort(long long int array[],int a,int b)                  //Defining the mergesort function 
{
	int mid;                                                   //Declaring the integer variables which are used    
		if(a<b)                                             
		{	
			mid=(a+b)/2;                               //Middle element index
			mergesort(array,a,mid);                    //Calling the mergesort function again for 1st half of elements(recursion)	
			mergesort(array,mid+1,b);                  //Calling the mergesort function again for 2nd half of elements(recursion)
			merge(array,a,mid,b);                      //Calling the merge function to merge two lower sorted arrays in sorted order
		}			
}
void merge(long long int array[],int a,int mid,int b)              //Defining the merge function which merges two arrays
{
	long long int l[mid-a+1],r[b-mid];                         //Declaring long long int sub-arrays.l for left and r for right
	int i,j,k;                                                
	for(i=0;i<mid-a+1;i++)
		{
			l[i]=array[a+i];                           //Storing values into left array from the array 
		}
	for(i=0;i<b-mid;i++)
		{
			r[i]=array[mid+i+1];                       //Storing values into right array from the array 
		}
	k=a;
	i=0;
	j=0;
	while(i<mid-a+1 && j<b-mid)                               //Selecting elements from each of left and right array    
		{
			if(l[i]<r[j])                             //Comparing one element in left array and one element in right array and storing the lowest into array       
				{
					array[k]=l[i];
					i++;
					k++;
				}
			else
				{
					array[k]=r[j];            //Comparing one element in left array and one element in right array and adding the lowest into array  
					j++;
					k++;
				}	
		}
	while(i<mid-a+1)                                         //Adding the remaining elements in left array into the array 
		{
			array[k]=l[i];
			i++;
			k++;
		}
	while(j<b-mid)					 	 //Adding the remaining elements in right array into the array
		{
			array[k]=r[j];
			j++;
			k++;
		}
	no_of_merges+=1;			                 //Counting the number of times merge function is called
}
int main()
{
	int i,n;                                                 //Declaring the integer variables   
	scanf("%d",&n);                                          //Taking the input of number of elements in the array  
	long long int array[n];                                  //Declaring the array to be sorted as long long int  
	for(i=0;i<n;i++)                                           
		{	
			scanf("%lld,",&array[i]);                //Taking the inputs of elements in array which is to be sorted
		}	
	mergesort(array,0,n-1);                                  //Calling the mergesort function  
	for(i=0;i<n;i++)
		{
			printf("%lld ",array[i]);                //Printing the elements of sorted array
		}	
	printf("\n%d",no_of_merges);	                         //Printing the number of merges
}
