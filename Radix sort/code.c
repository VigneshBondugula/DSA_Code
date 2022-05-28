#include<stdio.h>
int main()
{
	int k=0,len=0,i=0,d;
	int C[10];
	scanf("%d",&d);
	scanf("%d",&len);
	int A[len];
	for(i=0;i<len-1;i++)
	{
		scanf("%d ",&A[i]);
	}scanf("%d",&A[i]);

	int b=1;
	while(d--)
	{
		for(i=0;i<10;i++)
		{
			C[i]=0;
		}
		for(i=0;i<len;i++)
		{
			C[(A[i]/b)%10]++;
		}
		for(i=1;i<10;i++)
		{
			C[i]=C[i]+C[i-1];
		}
		int B[len];
		for(i=len-1;i>=0;i--)
		{
			B[--C[(A[i]/b)%10]]=A[i];
		}
		for(i=0;i<len;i++)
		{
			A[i]=B[i];
		}
		b*=10;
	}
	for(i=0;i<len;i++)
	{
		printf("%d ",A[i]);
	}
}