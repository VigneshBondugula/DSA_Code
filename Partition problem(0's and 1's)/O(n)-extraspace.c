#include<stdio.h>
#include<string.h>
int BS(char s[],int n[],int len,int l,int r)
{
    int m=(l+r)/2;
    if(n[m]==len-1-m-n[len-1]+n[m])
    {
        return m;
    }
    else if(n[m]<len-1-m-n[len-1]+n[m]-1)
    {
        return BS(s,n,len,m+1,r);
    }
    else
    {
        return BS(s,n,len,l,m-1);
    }
    return 0;
}
int main()
{
    char s[100];
    scanf("%s",s);
    int len=strlen(s);
    int n[len],count=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]=='0')
        {
            count+=1;
        }
        n[i]=count;
    }
    printf("%d",BS(s,n,len,0,len)+1);
}