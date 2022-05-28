#include<stdio.h>          
int c=0;                     
int merge(long long int array[],int a,int mid,int b);             
int mergesort(long long int array[],int a,int b)              
{
	int mid;                                                       
		if(a<b)                                             
		{	
			mid=(a+b)/2;                              
			mergesort(array,a,mid);
            mergesort(array,mid+1,b);
            merge(array,a,mid,b);                     
		}	
    return c;		
}
int merge(long long int array[],int a,int mid,int b) 
{
	long long int l[mid-a+1],r[b-mid];                
	int i,j,k;                                                
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
    int p;
	while(i<mid-a+1 && j<b-mid)                              
		{
            p=0;
            // if(l[i]>2*r[j])
            //     {
            //         c+=mid-i;
            //     }
            // else if(l[i]==2*r[j])
            //     {
            //         c+=mid-i-1;
            //     }
            while(l[p]<2*r[j] && p<mid-a+1)
            {
                p++;
            }if(l[p]>=2*r[j]) c+=mid-p-a+1;

			if(l[i]<r[j])                              
				{
					array[k]=l[i];
					i++;
					k++;
				}
            else
				{
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
    printf("%d\n",c);
    for(i=0;i<5;i++)
	{
			printf("%lld ",array[i]);                
	}printf("\n");
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
	printf("%d\n",mergesort(array,0,n-1));              
	for(i=0;i<n;i++)
		{
			printf("%lld ",array[i]);                
		}	                         
}
