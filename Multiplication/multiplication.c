#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100000
int main()
{
	char n;
	int num,c=0,d=0;
	long int k=0,len1=0,len2=0,i=0;
	FILE* fp;
	fp=fopen("num1","r");
	int num1[N],temp[N],num2[N],product[2*N];
    memset(product, 0, N*sizeof(product[0]));

	while((n=fgetc(fp))!=EOF)
	{
        num=(int)n-'0';
		num1[len1]=num;
		len1++;
	}
	fclose(fp);
    i=0;
    fp=fopen("num2","r");
	while((n=fgetc(fp))!=EOF)
	{
        num=(int)n-'0';
		num2[len2]=num;
		len2++;
	}
	fclose(fp);

    for(i=0;i<len2;i++)
	{
        for(int j=0;j<len1;j++)
        {
		    c=c+(num1[len1-j-1]*num2[len2-i-1]);
            d=d+product[len1*len2-j-i]+c%10;
	        product[len1*len2-j-i]=d%10;
            d=d/10;
		    c=c/10;
        }
	}
	product[0]=c;

    for(i=0;i<len1*len2+1;i++)
	{
		// printf("%d  %d\n",num1[i],num2[i]);
		printf("%d",product[i]);
	}
}