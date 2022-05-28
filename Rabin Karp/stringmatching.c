#include<stdio.h>
#define H 99929
int main()
{
    int T[10000],P[500];
    char n;
	int num,y,j,N;
	long int len1=0,len2=0,i=0;
	FILE* fp;
	fp=fopen("strings","r"); 
	while((n=fgetc(fp))!='\n')
	{
        num=(int)n-'0';
		T[len1]=num;
		len1++;
	}
    while((n=fgetc(fp))!=EOF)
	{
        num=(int)n-'0';
		P[len2]=num;
		len2++;
	}
	fclose(fp);
    //Converting P and y to integers
    N=P[0];
    y=T[0];
    num=2;
    for(i=1;i<len2;i++)
    {
        num=(num*2)%H;
        N=(2*N+P[i])%H;
        y=(2*y+T[i])%H;
    }
    if(N==y)
    {
        for(j=0;j<len2;j++)
        {
            if(P[j]!=T[j])
            {
                break;
            }
        }
        if(j==len2)
        {
            printf("Matching at index 1\n");
        }
    }
    //Shifting y to right stepwise
    for(i=1;i<=len1-len2;i++)
    {
        y=(2*y-num*T[i-1]+T[i+len2-1])%H;
        if(N==y)
        {
            for(j=0;j<len2;j++)
            {
                if(P[j]!=T[i+j])
                {break;}
            }
            if(j==len2)
            {
                printf("Matching at index %ld\n",i+1);
            }
        }
    }

    // for(i=0;i<len1;i++)
    // {
    //     printf("%d",T[i]);
    // }
    // printf("\n");
    // for(i=0;i<len2;i++)
    // {
    //     printf("%d",P[i]);
    // }
    // printf("\n%d   %d",hN,hy);
}