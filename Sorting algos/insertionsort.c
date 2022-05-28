#include<stdio.h>

int insertionsort(long long int array[])
{
    long long int t,j;
    for(int i=1;i<20;i++)
    {
        t=array[i];
        j=i-1;
        while(j>=0 && array[j]>t)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=t;
    }
    for(int i=0;i<20;i++)
	{
		printf("%lld ",array[i]); 
    }
}

int main()
{
	long long int array[20];                  
	int i;	                                  
	for(i=0;i<20;i++)
		{	
			scanf("%lld,",&array[i]); 
		}	
	insertionsort(array);                        
}