#include<stdio.h>
#include<stdlib.h>
#define H 99929
int max=0;
struct node
{
    int data;
    struct node* next;
    int count;
};
struct node* hash_table[H];

// void create_hashtable()
// {
//     for(long int i=0;i<H;i++)
//     {
//         struct node* head=(struct node*)malloc(sizeof(struct node));
//         head->data=0;
//         head->next=NULL;
//         hash_table[i]=head;
//     }
// }
void clear_hash_table()
{
    struct node* temp;
    for(long int i=0;i<H;i++)
    {
        while(hash_table[i]!=NULL)
        {
            temp=hash_table[i]->next;
            free(hash_table[i]);
            hash_table[i]=temp;
        }  
    }
}

void insert(int k,int hN)
{
    struct node* hashed_value=(struct node*)malloc(sizeof(struct node));
    hashed_value->data=k;
    hashed_value->count=1;
    hashed_value->next=hash_table[hN];
    hash_table[hN]=hashed_value;
}

int check(int T[],int k,int len1,int l)
{
    int index,num,y,j=0,N,hN,hy;
    struct node* head;
    int i=0;    
    y=T[0];
    num=2;
    for(i=1;i<l;i++)
    {
        num*=2;
        y=2*y+T[i];
    }
    hy=y%H;
    if(hy<0) hy=hy+H;
    insert(0,hy);
    for(i=1;i<=len1-l;i++)
    {
        hy=hy*2+(T[i+l-1]-num*T[i-1])%H;
        if(hy<0) hy=hy+H;
        if(hash_table[hy]==NULL)
        {
            insert(i,hy);
        }
        else
        {
            head=hash_table[hy];
            while(hash_table[hy]!=NULL)
            {
                index=hash_table[hy]->data;
                for(j=0;j<l;j++)
                {
                    if(T[i+j]!=T[index+j])
                    {
                        insert(i,hy);
                        break;
                    }
                }
                if(j==l)
                {
                    hash_table[hy]->count+=1;
                    if(hash_table[hy]->count=k)
                    {
                        clear_hash_table();
                        return 1;
                    }
                }
                hash_table[hy]=hash_table[hy]->next;
            }
            hash_table[hy]=head;
        }
    }
    return 0;
}
int BS(int T[],int k,int len1,int l,int r)
{
    int m;
    m=(l+r)/2;
    printf("%d %d %d %d\n",l,r,m,max);
    if(l>r)
    {
        return max;
    }
    else if(check(T,k,len1,m))
    {
        if(m>max)
        {
            max=m;
        }
        BS(T,k,len1,m+1,r);
    }
    else
    {
        BS(T,k,len1,l,m-1);
    }
}
int main()
{
    int T[1000];
    char n;
    int k;
    int num,len1=0;
    FILE* fp;
    fp=fopen("string","r");
    while((n=fgetc(fp))!=EOF)
    {
        num=(int)n-'0';
        T[len1]=num;
        len1++;
    }
    fclose(fp);
    scanf("%d",&k);
    printf("%d",BS(T,k,len1,0,len1-k));
}