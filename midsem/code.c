#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int A[n],B[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&B[i]);
    }
    int S[n],L[n],R[n];
    int top=-1;
    
    //Left Maximums
    for(i=0;i<n;i++)
    {
        if(top<0)
        {
            S[++top]=i;
        }
        else if(A[S[top]]>=A[i] && B[S[top]]>=B[i])
        {
            S[++top]=i;
        }
        else
        {
            while(top>=0 && A[S[top]]<=A[i] && B[S[top]]<=B[i])
                {
                    L[S[top--]]=i;
                }
            S[++top]=i;
        }
    }
    while(top>=0)
    {
        L[S[top--]]=-1;
    }

    for(i=0;i<n;i++)
    {  
        printf("%d ",L[i]);
    }

    //Right Maximums
    for(i=n-1;i>=0;i--)
    {
        if(top<0)
        {
            S[++top]=i;
        }
        else if(A[S[top]]>=A[i] && B[S[top]]>=B[i])
        {
            S[++top]=i;
        }
        else
        {
            while(top>=0 && A[S[top]]<=A[i] && B[S[top]]<=B[i])
                {
                    R[S[top--]]=i;
                }
            S[++top]=i;
        }
    }
    while(top>=0)
    {
        R[S[top--]]=-1;
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",R[i]);
    }

    printf("\n");
    for(i=0;i<n;i++)
    {
        if(L[i]>=0 || R[i]>=0)
        {
            printf("%d ",i);
        }
    }
}