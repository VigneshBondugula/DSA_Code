#include<stdlib.h>
/*MERGE SORT*/
#include<stdio.h>
void merge(int array[],int B[],long long int a,long long int mid,long long int b);             //Declaring the merge function which is called in mergesort function   
void mergesort(int array[],int B[],long long int a,long long int b)                  //Defining the mergesort function 
{
	int mid;                                                   //Declaring the integer variables which are used    
		if(a<b)                                             
		{	
			mid=(a+b)/2;                               //Middle element index
			mergesort(array,B,a,mid);                    //Calling the mergesort function again for 1st half of elements(recursion)	
			mergesort(array,B,mid+1,b);                  //Calling the mergesort function again for 2nd half of elements(recursion)
			merge(array,B,a,mid,b);                      //Calling the merge function to merge two lower sorted arrays in sorted order
		}			
}
void merge(int array[],int B[],long long int a,long long int mid,long long int b)              //Defining the merge function which merges two arrays
{
	long long int l[mid-a+1],r[b-mid],l2[mid-a+1],r2[b-mid];                         //Declaring long long int sub-arrays.l for left and r for right
	int i,j,k;                                                
	for(i=0;i<mid-a+1;i++)
		{
			l[i]=array[a+i];                           
            l2[i]=B[a+i];
		}
	for(i=0;i<b-mid;i++)
		{
			r[i]=array[mid+i+1];                       //Storing values into right array from the array 
            r2[i]=B[mid+i+1];
		}
	k=a;
	i=0;
	j=0;
	while(i<mid-a+1 && j<b-mid)                               //Selecting elements from each of left and right array    
		{
			if(l[i]<r[j])                             //Comparing one element in left array and one element in right array and storing the lowest into array       
				{
					array[k]=l[i];
                    B[k]=l2[i];
					i++;
					k++;
				}
			else
				{
					array[k]=r[j];    
                    B[k]=r2[j];
					j++;
					k++;
				}	
		}
	while(i<mid-a+1)                                         
		{
			array[k]=l[i];
            B[k]=l2[i];
			i++;
			k++;
		}
	while(j<b-mid)					 	 
		{
			array[k]=r[j];
            B[k]=r2[j];
			j++;
			k++;
		}
}
int main()
{
    long long int n=100000,i,count=0;
    int A[n],B[n];
    for(i=0;i<n;i++)
    {
        A[i]=rand();
    }
    for(i=0;i<n;i++)
    {
        B[i]=rand();
    }
    mergesort(A,B,0,n-1);
    // for(i=0;i<n;i++)
    // {
    //     printf("%d ",B[i]);
    // }
    int S[n],L[n];
    int top=-1;
      //Left Maximums
    for(i=0;i<n;i++)
    {
        if(top<0)
        {
            S[++top]=i;
        }
        else if(B[S[top]]>=B[i])
        {
            S[++top]=i;
        }
        else
        {
            while(top>=0 && B[S[top]]<=B[i])
                {
                    L[S[top--]]=i;
                }
            S[++top]=i;
        }
    }
    while(top>=0)
    {
        L[S[top--]]=-1;
    }
    // printf("\n");
    // for(i=0;i<n;i++)
    // {  
    //     printf("%d ",L[i]);
    // }
    for(i=0;i<n;i++)
    {  
        if(L[i]>0)
        {
            count+=1;
        }
    }printf("%lld",count);
}