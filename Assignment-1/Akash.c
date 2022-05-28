#include<stdio.h>
#include<stdlib.h>
int BIT[27][1000001];
int N;
void IN(int index,int x,int i)
{
    while(i<=N)
    {
        BIT[index][i]+=x;
        i+=i&(-i);
    }
}
int query(int index,int i)
{
    int s=0;
    while(i>0)
    {
        s+=BIT[index][i];
        i-=i&(-i);
    }
    return s;
}
int main()
{
    int Q;
    scanf("%d %d",&N,&Q);
    char A[N];
    scanf("%s",A);
    for(int i=0;i<N;i++)
    {
        IN(A[i]-'a',1,i+1);
    }
    for(int i=0;i<Q;i++)
    {
        int choice;
        scanf("%d",&choice);
        if(choice==0)
        {
            int index;
            char c;
            scanf("%d %c",&index,&c);
            int y = A[index-1]-'a';
            IN(y,-1,index);
            A[index-1]=c;
            y = A[index-1]-'a';
            IN(y,1,index);
        }
        if(choice==1)
        {
            int left_limit,right_limit,k;
            scanf("%d %d %d",&left_limit,&right_limit,&k);
            int sum=0;
            if (left_limit > right_limit || right_limit - left_limit + 1 <k)
            {printf("Out of range\n");}
            else
            {
                int j;
                for(j=0;j<26;j++)
                {
                    sum+=query(j,right_limit)-query(j,left_limit-1);
                    if(sum>=k)
                    {
                        break;
                    }
                }
                printf("%c\n",'a'+j);
            }    
        }

    }
}