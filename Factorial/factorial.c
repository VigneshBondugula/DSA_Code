#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100000
int multiply(int num1[],int num2[],int len1,int len2,int factorial[])
{
	int c,d;
	long int i=0,k=0;
	for(i=0;i<len2;i++)
	{
        for(int j=0;j<len1;j++)
        {
		    c=c+(num1[len1-j-1]*num2[len2-i-1]);
            d=d+factorial[len1*len2-j-i]+c%10;
	        factorial[len1*len2-j-i]=d%10;
            d=d/10;
		    c=c/10;
        }
	}
	factorial[0]=c;
}
int main()
{
	char n;
	int num1[10000],num2[10000];
	long int m,i=0,len=0;
	FILE* fp;
	scanf("%d",&m);
	int factorial[N];
    memset(factorial, 0, N*sizeof(factorial[0]));
	num1[0]=1;
    for(i=0;i<len;i++)
	{
		// printf("%d  %d\n",num1[i],num2[i]);
		printf("%d",factorial[i]);
	}
}
