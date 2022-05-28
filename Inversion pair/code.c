
#include<stdio.h>                               
int merge(long long int array[],int a,int mid,int b);             
int mergesort(long long int array[],int a,int b)              
{
	int mid;                                                       
		if(a<b)                                             
		{	
			mid=(a+b)/2;                              
			return mergesort(array,a,mid)+mergesort(array,mid+1,b)+merge(array,a,mid,b);                     
		}			
}
int merge(long long int array[],int a,int mid,int b) 
{
	long long int l[mid-a+1],r[b-mid];                
	int i,j,k,c=0;                                                
	for(i=0;i<mid-a+1;i++)
		{
			l[i]=array[a+i];
        }                          
	for(i=0;i<b-mid;i++)
		{
			r[i]=array[mid+i+1];                      
		}
	k=a;
	i=0;
	j=0;
	while(i<mid-a+1 && j<b-mid)                              
		{
			if(l[i]<r[j])                              
				{
					array[k]=l[i];
					i++;
					k++;
				}
			else
				{
                    c+=mid-i;
					array[k]=r[j];            
					j++;
					k++;
				}	
		}
	while(i<mid-a+1)                          
		{
			array[k]=l[i];
			i++;
			k++;
		}
	while(j<b-mid)					 	 
		{
			array[k]=r[j];
			j++;
			k++;
        }
    return c;
}
int main()
{
	int i,n;                             
	scanf("%d",&n);                      
	long long int array[n];                
	for(i=0;i<n;i++)                                           
		{	
			scanf("%lld,",&array[i]);    
		}	
	printf("%d",mergesort(array,0,n-1));              
	for(i=0;i<n;i++)
		{
			printf("%lld ",array[i]);                
		}	                         
}
