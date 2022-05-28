#include<stdio.h>
#include<string.h>
int main()
{
	char n;
	int A[100],num,c=0;
	int k=0,len=0,i=0;
	FILE* fp;
	fp=fopen("input","r"); 
	while((n=fgetc(fp))!=EOF)
	{
        num=(int)n-'0';
		A[len]=num;
		len++;
	}
	fclose(fp);
	int C[10];
	for(i=0;i<10;i++)
	{
		C[i]=0;
	}
	for(i=0;i<len;i++)
	{
		C[A[i]]++;
	}
	for(i=1;i<10;i++)
	{
		C[i]=C[i]+C[i-1];
	}
	int B[len];
	for(i=len-1;i>=0;i--)
	{
		B[--C[A[i]]]=A[i];
	}
	for(i=0;i<len;i++)
	{
		printf("%d ",B[i]);
	}
}