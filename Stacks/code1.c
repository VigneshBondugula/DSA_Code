#include<stdio.h>
int main()
{
    int n,i=0;
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    int S[n],B[n];
    int top=-1;
    for(i=0;i<n;i++)
    {
        if(top<0)
        {
            S[++top]=i;
        }
        else if(A[S[top]]<A[i])
        {
            S[++top]=i;
        }
        else
        {
            while(top>=0 && A[S[top]]>=A[i])
                {
                    B[S[top--]]=i;
                }
            S[++top]=i;
        }
    }
    while(top>=0)
    {
        B[S[top--]]=-1;
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",B[i]);
    }
}