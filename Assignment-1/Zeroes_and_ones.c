#include<stdio.h>
#include<stdlib.h>
int fill_zeroes(int n)
{
    int x=1;
    while(x<n)
    {
        x*=2;
    }
    return x;
}

void Build(int ST[],int n,int num)
{
    int i=0;
    for(i=0;i<num;i++)
    {
        if(i<n)
        {
            ST[num+i-1]=1;
        }
        else
        {
            ST[num+i-1]=0;
        }
    }
    for(i=num-2;i>-1;i--)
    {
        ST[i]=ST[2*i+1]+ST[2*i+2];
    }    
}

void Update(int ST[],int num,int index)
{
    if(ST[num-1+index]==0) return;
    ST[num-1+index]=0;
    int p=((num-1+index)-1)/2;
    while(p>0)
    {
        ST[p]-=1;
        p=(p-1)/2;
    }
    ST[0]-=1;
}

int k_one(int ST[],int num,int k, int l,int r,int p)
{
    if(k>ST[p]) return -1;
    else if(k==ST[p] && l==r)
    {
        return r;
    }
    int m,left,right;
    m=(l+r)/2;
    left=k_one(ST,num,k,l,m,2*p+1);
    if(left==-1)
    {
        right=k_one(ST,num,k-ST[2*p+1],m+1,r,2*p+2);
        return right;
    }
    else
    {
        return left;
    }  
}
int main()
{
    int i,n,num;
    scanf("%lld",&n);
    num=fill_zeroes(n);
    int* ST = calloc(4*n,sizeof(int));
    Build(ST,n,num);
    int num_of_opr;
    scanf("%d",&num_of_opr);
    for(i = 0; i<num_of_opr; i++)
    {
        int query,index;
        scanf("%d %d",&query,&index);
        if(query==0)
        {
            Update(ST,num,index-1);
        }
        if(query==1)
        {
            int x=k_one(ST,num,index,0,num-1,0);
            if(x!=-1)
            {
                printf("%d\n",x+1);
            }
            else
            {
                printf("-1\n");
            }
            
        }
    }
}