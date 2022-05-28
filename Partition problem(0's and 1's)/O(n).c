#include<stdio.h>
#include<string.h>
int partition(char s[],int l,int r)
{
    int c0=0,c1=0;
    while(l<=r)
    {
        if(s[l]=='0' && c0<=c1)
        {
            c0++;
            l++;
        }
        else if(c0<=c1){
            l++;
        }
        if(s[r] == '1' && c0>=c1)
        {
            c1++;
            r--;
        }
        else if(c0>=c1){
            r--;
        }
    }
  
    if(c0<c1 && l-r==2)
    {
        printf("%d",l);
    }
    else if(c0<c1)
    {
        printf("%d",l+1);
    }
    else if(c0==c1)
    {
        printf("%d",l);
    }
    else if(c0>c1 && l-r==2)
    {
        printf("%d",r+1);
    }   
    else
    {
        printf("%d",r);
    }   
    printf("\n%d %d %d %d",c0,c1,l,r);
}
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    partition(s,0,len-1);
}