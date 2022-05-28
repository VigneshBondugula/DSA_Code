#include<stdio.h>
int main()
{
	int i,j,n;                             
	scanf("%d",&n);                      
	long long int array[n];                
	for(i=0;i<n;i++)                                           
		{	
			scanf("%lld,",&array[i]);    
		}
    int c=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(array[i]>array[j])
            {
                c++;
            }
        }
    }
    printf("%d",c);
}