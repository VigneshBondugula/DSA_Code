#include<stdio.h>
#include<string.h>
int partition(char s[],int l,int r)
{
    int c0=0,c1=0;
    int n=r+1;
    while(l<r)
    {
       while(l<n)
       {
           if(s[l]=='0')
           {
               c0++;
               break;
           }
           else if(l!=n-1)
           {
               l++;
           }
           else if(l==n-1)
           {
               break;
           }
       }
        while(r>=0)
       {
           if(s[r]=='1')
           {
               c1++;
               break;
           }
           else if(r!=0)
           {
               r--;
           }
           else if(r==0)
           {
               break;
           }
       }
        if((l<n-1 && r>0) || l<r)
        {
            l++;
            r--;
        } 
    }
    if((c0==1 || c1==1) && l>r)
    {
        printf("The index does not exist");
    }
    else
    {
        printf("%d",l-1);
    }
    
}
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    partition(s,0,len-1);
}