#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 1000000	
int num1[N],temp[N],num2[N],sum[N+1];

int main()
{
	char n;
	int num,c=0;
	long int k=0,len1=0,len2=0,i=0;
	FILE* fp;
	fp=fopen("num1","r");
	// memset(num1, 0, N*sizeof(num1[0]));
	// memset(num2, 0, N*sizeof(num2[0])); 
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
	if(len1>len2)
	{
		for(i=0;i<len1-len2;i++)
		{
			temp[i]=0;
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
			temp[i]=0;
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
	    	if(c%10<0){sum[N-i]=10+c%10;}
        	else{sum[N-i]=c%10;}
			c=c/10;
		}
		else if(k==len2){
			c=c+temp[N-1-i]+num2[N-1-i];
	    	if(c%10<0){sum[N-i]=10+c%10;}
        	else{sum[N-i]=c%10;}
			c=c/10;
		}
		else
		{
			c=c+num1[N-1-i]+num2[N-1-i];
	    	if(c%10<0){sum[N-i]=10+c%10;}
        	else{sum[N-i]=c%10;}
			c=c/10;
		}	
	}
	sum[0]=c;
	if(len1==len2)
	{
		k=len1;
	}
	for(i=0;i<k+1;i++)
	{
		// printf("%d  %d\n",num1[i],num2[i]);
		printf("%d",sum[i]);
	}
}

