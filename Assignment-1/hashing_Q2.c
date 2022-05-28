#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define P 299

struct heapnode
{
    int freq;
    int index;
    struct node* node;
};

int count=0;

struct node
{
    int key;
    struct node* next;
    struct node* prev;
    struct heapnode* hnode;
};

void bottom_up_heapify(struct heapnode** heap,int i)
{
    int p=(i-1)/2;
    int t;
    while(p>=0 && heap[p]->freq < heap[i]->freq)
    {
        t=heap[i]->freq;
        heap[i]->freq=heap[p]->freq;
        heap[p]->freq=t;
        heap[i]->index=p;
        heap[p]->index=i;
        i=p;
        p=(i-1)/2;
    }
}

void top_down_heapify(struct heapnode** heap,int i,int n)
{
    int l,t;
    while(2*i+2<n)
    {
        if(heap[2*i+1]->freq > heap[2*i+2]->freq) l=2*i+1;
        else l=2*i+2;
        if(heap[i]->freq < heap[l]->freq)
        {
            t=heap[i]->freq;
            heap[i]->freq=heap[l]->freq;
            heap[l]->freq=t;
            heap[i]->index=l;
            heap[l]->index=i;
        }
        else break;
    }
    if(2*i+1<n && heap[i]->freq < heap[2*i+1]->freq)
    {
        t=heap[i]->freq;
        heap[i]->freq=heap[2*i+1]->freq;
        heap[2*i+1]->freq=t;
        heap[i]->index=2*i+1;
        heap[2*i+1]->index=i;
    }
}
void update(struct heapnode** heap,int i,int x)
{
    if(heap[i]->freq > x)
    {
        heap[i]->freq=x;
        top_down_heapify(heap,i,count); 
    }
    if(heap[i]->freq < x)
    {
        heap[i]->freq=x;
        bottom_up_heapify(heap,i);
    }

}
int check(struct node** hash_table,struct heapnode** heap,int index,int value)
{
    struct node* temp;
    while(hash_table[index]!=NULL)
    {
        if(hash_table[index]->key == value)
        {
            update(heap,hash_table[index]->hnode->index,(hash_table[index]->hnode->freq)+1);
            return 1;
        }
        temp=hash_table[index]->next;
        hash_table[index]=temp;
    }
    return 0;
}
void insert(struct node** hash_table,struct heapnode** heap,int key) 
{
    int index = key % P; 
    struct node* prevHead = hash_table[index]; 
    if(!check(hash_table,heap,index,key))
    {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        struct heapnode* newheapNode = (struct heapnode*)malloc(sizeof(struct heapnode));
        newheapNode->freq=1;
        newheapNode->index=count;
        newNode->key = key;
        newNode->prev != NULL;
        newNode->next = prevHead; 
        if(prevHead) prevHead->prev=newNode;
        newheapNode->node=newNode;
        newNode->hnode=newheapNode;
        hash_table[index] = newNode;
        heap[count++]=newheapNode;
        bottom_up_heapify(heap,count-1);
    }
}

int delete_max_freq(struct node** hash_table,struct heapnode** heap)
{
    struct node* temp;
    if(heap[0])
    {
        int deleted=heap[0]->freq;
        while(heap[0]->freq==deleted)
        {
            temp=heap[0]->node;
            if(temp->prev) temp->prev->next=temp->next;
            if(temp->next) temp->next->prev=temp->prev;
            free(temp);
            heap[0] = heap[--count];
            free(heap[count+1]);
            top_down_heapify(heap,0,count);
        }
        return deleted;
    }
}

int main()
{
    struct node** hash_table = (struct node**)malloc(sizeof(struct node*) * P);  
    memset(hash_table, 0, sizeof(struct node*) * P);
    struct heapnode** heap = (struct heapnode**)malloc(sizeof(struct heapnode*) * P);  
    memset(heap, 0, sizeof(struct heapnode*) * P);

    insert(hash_table,heap,1);
    insert(hash_table,heap,1);
    insert(hash_table,heap,1);
    insert(hash_table,heap,1);
    insert(hash_table,heap,2);
    insert(hash_table,heap,2);
    insert(hash_table,heap,3);
    insert(hash_table,heap,3);
    insert(hash_table,heap,3);
    insert(hash_table,heap,3);
    insert(hash_table,heap,4);
    insert(hash_table,heap,4);
    insert(hash_table,heap,4);

    

    // top_down_heapify(heap,0,count);
    printf("%d\n",delete_max_freq(hash_table,heap));// Prints 4 because 4 1's and 4 3's are there and deletes them
    printf("%d\n",delete_max_freq(hash_table,heap));
    printf("%d\n",delete_max_freq(hash_table,heap));

}
