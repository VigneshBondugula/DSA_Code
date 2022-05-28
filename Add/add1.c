#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define N 1000000
int temp[N],num1[N],num2[N];
int main()
{
	int num;
    char n[10000];
	long int c=0,i=0;
	FILE* fp;
	fp=fopen("num1","r");
    long int k=0,len1=0,len2=0,sum[N+1];
	while(fgets(n,5,fp))
	{
        num=atoi(n);
		num1[len1]=num;
		len1++;
	}
	fclose(fp);
    fp=fopen("num2","r");
	while(fgets(n,5,fp))
	{
        num=atoi(n);
		num2[len2]=num;
		len2++;
	}
	fclose(fp);
	if(len1>len2)
	{
		for(i=0;i<len1-len2;i++)
		{
			temp[i]=0000;
		}
		while(i<len1)
		{
			temp[i]=num2[i-len1+len2];
			i++;
		}
		k=len1;
	}
	if(len2>len1)
	{
		for(i=0;i<len2-len1;i++)
		{
			temp[i]=0000;
		}
		while(i<len2)
		{
			temp[i]=num1[i-len2+len1];
			i++;
		}
		k=len2;
	}
	for(i=0;i<N;i++)
	{
		if(k==len1){
			c=c+num1[N-1-i]+temp[N-1-i];
	    	if(c%10000<0){sum[N-i]=10000+c%10000;}
        	else{sum[N-i]=c%10000;}
			c=c/10000;
		}
		else if(k==len2){
			c=c+temp[N-1-i]+num2[N-1-i];
	    	if(c%10000<0){sum[N-i]=10000+c%10000;}
        	else{sum[N-i]=c%10000;}
			c=c/10000;
		}
		else
		{
			c=c+num1[N-1-i]+num2[N-1-i];
	    	if(c%10000<0){sum[N-i]=10000+c%10000;}
        	else{sum[N-i]=c%10000;}
			c=c/10000;
		}
		
	}
	sum[0]=c;
	if(len1==len2)
	{
		k=len1;
	}
	for(i=0;i<k+1;i++)
	{
		printf("%d  %d\n",num1[i],temp[i]);
		// printf("%ld",sum[i]);
	}
}

