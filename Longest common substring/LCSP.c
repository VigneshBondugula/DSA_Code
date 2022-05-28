#include<stdio.h>
#include<stdlib.h>
#define H 99929
struct node
{
    int data;
    struct node* next;
};
struct node* hash_table[H];

void create_hashtable()
{
    for(long int i=0;i<H;i++)
    {
        struct node* head=(struct node*)malloc(sizeof(struct node));
        head->data=0;
        head->next=NULL;
        hash_table[i]=head;
    }
}
void clear_hash_table()
{
    struct node* temp;
    for(long int i=0;i<H;i++)
    {
        while(hash_table[i]->next!=NULL)
        {
            temp=hash_table[i]->next;
            free(hash_table[i]);
            hash_table[i]=temp;
        }
        // temp->data=0;
        // temp->next=NULL;
        // hash_table[i]=temp;    
    }
}

void insert(int k,int hN)
{
    struct node* hashed_value=(struct node*)malloc(sizeof(struct node));
    hashed_value->data=k;
    hashed_value->next=NULL;
    struct node* head=hash_table[hN];

    while(hash_table[hN]->next!=NULL)
    {
        hash_table[hN]=hash_table[hN]->next;
    }
    hash_table[hN]->next=hashed_value;
    hash_table[hN]=head;
}

int check(int T1[],int T2[],int len1,int len2,int l)
{
    int index,num,y,j=0,N,hN,hy,k=0;
    struct node* head;
    int i=0;    
    //CREATING HASH TABLE
    y=T2[0];
    num=2;
    for(i=1;i<l;i++)
    {
        num*=2;
        y=2*y+T2[i];
    }
    hy=y%H;
    if(hy<0) hy=hy+H;
    insert(0,hy);
    for(i=1;i<=len2-l;i++)
    {
        hy=hy*2+(T2[i+l-1]-num*T2[i-1])%H;\
        if(hy<0) hy=hy+H;
        insert(i,hy);
    }

    //ROLLING HASH THROUGH T1
    y=T1[0];
    num=2;
    for(i=1;i<l;i++)
    {
        num*=2;
        y=2*y+T1[i];
    }
    hy=y%H;
    if(hy<0) hy=hy+H;
    head=hash_table[hy];
    while(hash_table[hy]->next!=NULL)
    {
        index=hash_table[hy]->next->data;
        for(i=0;i<l;i++)
        {
            if(T1[i]!=T2[index+i])
            {break;}
        }
        if(i==l)
        {
            clear_hash_table();
            // printf("The substring of length %d matches at index 1 of T1 and index %d of T2\n",l,index+1);
            return 1;
        }
        hash_table[hy]=hash_table[hy]->next;
    }
    hash_table[hy]=head;
    for(i=1;i<=len1-l;i++)
    {
        hy=hy*2+(T1[i+l-1]-num*T1[i-1])%H;
        if(hy<0) hy=hy+H;
        head=hash_table[hy];
        while(hash_table[hy]->next!=NULL)
        {
            index=hash_table[hy]->next->data;
            for(k=0;k<l;k++)
            {
                if(T1[i+k]!=T2[index+k])
                {break;}
            }
            if(k==l)
            {
                clear_hash_table();
                // printf("The substring of length %d matches at index %d of T1 and index %d of T2\n",l,i,index+1);
                return 1;
            }
            hash_table[hy]=hash_table[hy]->next;
        }
        hash_table[hy]=head;
    }
    return 0;
}
int BS(int T1[],int T2[],int len1,int len2,int l,int r)
{
    int k;
    k=(l+r)/2;
    static int max=0;
    // printf("%d  %d\n",k,max);
    if(l>r)
    {
        return max;
    }
    // if(check(T1,T2,len1,len2,k)==1 && check(T1,T2,len1,len2,k+1)!=1)
    // {
    //     return k;
    // }
    else if(check(T1,T2,len1,len2,k))
    {
        // if(k>max)
        // {
        //     max=k;
        // }
        max=k;
        max=BS(T1,T2,len1,len2,k+1,r);
    }
    else
    {
        max=BS(T1,T2,len1,len2,l,k-1);
    }
    return max;
}
int main()
{
    int T1[1000],T2[1000];
    char n;
    int num,len1=0,len2=0 ;
    create_hashtable();
    FILE* fp;
    fp=fopen("strings","r");
    while((n=fgetc(fp))!='\n')
    {
        num=(int)n-'0';
        T1[len1]=num;
        len1++;
    }
    while((n=fgetc(fp))!=EOF)
    {
        num=(int)n-'0';
        T2[len2]=num;
        len2++;
    }
    fclose(fp);
    printf("%d",BS(T1,T2,len1,len2,0,len2));
}