// #include<stdio.h>
// int main()
// {
//     int n,i;
//     scanf("%d",&n);
//     int A[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&A[i]);
//     }
//     int S[n],L[n],R[n];
//     int top=-1;
    
//     //Left Maximums
//     for(i=0;i<n;i++)
//     {
//         if(top<0)
//         {
//             S[++top]=i;
//         }
//         else if(A[S[top]]>A[i])
//         {
//             S[++top]=i;
//         }
//         else
//         {
//             while(top>=0 && A[S[top]]<=A[i])
//                 {
//                     L[S[top--]]=i;
//                 }
//             S[++top]=i;
//         }
//     }
//     while(top>=0)
//     {
//         L[S[top--]]=-1;
//     }
//     for(i=0;i<n;i++)
//     {  
//         printf("%d ",L[i]);
//     }

//     //Right Maximums
//     for(i=n-1;i>0;i--)
//     {
//         if(top<0)
//         {
//             S[++top]=i;
//         }
//         else if(A[S[top]]>A[i])
//         {
//             S[++top]=i;
//         }
//         else
//         {
//             while(top>=0 && A[S[top]]<=A[i])
//                 {
//                     R[S[top--]]=i;
//                 }
//             S[++top]=i;
//         }
//     }
//     while(top>=0)
//     {
//         R[S[top--]]=-1;
//     }
//     printf("\n");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",R[i]);
//     }
// }

#include<stdio.h>
int max(int*arr, int x,int y)
{
    int i,max = 0;
    for(i=x;i<y;i++)
    {
        if(max<arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
int trap(int* height, int heightSize)
{
    int i,sum=0,lmax,rmax,p;
    lmax = max(height,0,1);
    rmax = max(height,2,heightSize);
    for(i=1;i<heightSize-1;i++)
    {
        if(lmax<height[i-1])
        {
            lmax = height[i-1];
        }
        if(rmax==height[i])
        {
            rmax = max(height,i+1,heightSize);
        }
        p = (lmax<rmax) ? lmax : rmax;
        //printf("%d\n",p);
        if(p>height[i])
        {
            sum += p - height[i];
        }
    }
    return sum;
}
int main()
{
    int arr[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = trap(arr,12);
    printf("%d\n",ans);
}