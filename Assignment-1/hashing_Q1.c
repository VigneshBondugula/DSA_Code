#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define P 299
#define M 29

struct node
{
    int key;
    struct node* next;
    int count;
};


void insert(struct node** hash_table,int key,int value) 
{
    int index = key % P; 
    struct node* prevHead = hash_table[index]; 
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = value;
    newNode->count = 1;
    newNode->next = prevHead; 
    hash_table[index] = newNode;
}

struct node* get(struct node** hash_table,int key)
{
    int index = key % P;
    struct node* head = hash_table[index];
    return head; 
}

int compare(char* s1,char* s2,int len)
{
    while(len--)
    {
        if(*s1!=*s2) return 0;
        s1++;
        s2++;
    }
    return 1;
}

void clear_hash_table(struct node** hash_table)
{
    struct node* temp;
    for(long int i=0;i<P;i++)
    {
        while(hash_table[i])
        {
            temp=hash_table[i]->next;
            free(hash_table[i]);
            hash_table[i]=temp;
        }  
    }
    free(hash_table);
}

int check(char T[],int l,int k)
{
    int len=strlen(T);
    struct node** hash_table = (struct node**)malloc(sizeof(struct node*) * P);  // create
    memset(hash_table, 0, sizeof(struct node*) * P);
    int hash = 0;
    int h = 1;
    int i;
    for (i = 0; i < l; i++) {
        if (i > 0) h *= M;
        hash = hash * M + (T[i] - 'a' + 1);
        hash %= P;
        if(hash<0) hash+=P;
        h %= P;
        if(h<0) h+=P;
    }
    insert(hash_table,hash, 0);
    // printf("hash-%d\n",hash);
    for (i = l; i < len; i++) 
    {
        hash = (hash - h * (T[i - l] - 'a' + 1) + P) % P;
        hash = hash * M + (T[i] - 'a' + 1);
        hash %= P;
        if(hash<0) hash+=P;
        // printf("hash-%d\n",hash);
        struct node* head = get(hash_table,hash);
        while(head)
        {
            if(compare(T+head->key,T+i-l+1,l))
            {
                head->count+=1;
                if(head->count==k)
                {
                    clear_hash_table(hash_table);
                    return 1;
                }
                break;
            }
            head=head->next;
        }
        if(head==NULL)
        {
            insert(hash_table,hash,i-l+1);
        }
    }
    clear_hash_table(hash_table);
    return 0;
}

int main()
{
    char T[100];
    int k;
    scanf("%s",T);
    scanf("%d",&k);
    int ans=0;
    int l=1;
    int r=strlen(T);

    while (l <= r) 
    {
        int m = (l + r) / 2;
        // printf("%d %d %d %d\n",l,r,m,check(T,m,k));
        if (check(T,m,k)) 
        {
            if(m>ans) ans=m;
            l = m + 1;
        } 
        else 
        {
            r = m - 1;
        }
    }
    printf("%d\n", ans);
}