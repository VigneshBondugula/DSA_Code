#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List
{
  int i;
  struct List *next;
};


struct List *
newedge (struct List *node, int i)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->next = node;
  return temp;
}

struct QNode { 
    int key; 
    struct QNode* next; 
}; 
  
// The queue, front stores the front node of LL and rear stores the 
// last node of LL 
struct Queue { 
    struct QNode *front, *rear; 
}; 
  
// A utility function to create a new linked list node. 
struct QNode* newNode(int k) 
{ 
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode)); 
    temp->key = k; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to create an empty queue 
struct Queue* createQueue() 
{ 
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
    q->front = q->rear = NULL; 
    return q; 
} 
  
// The function to add a key k to q 
void enQueue(struct Queue* q, int k) 
{ 
    // Create a new LL node 
    struct QNode* temp = newNode(k); 
  
    // If queue is empty, then new node is front and rear both 
    if (q->rear == NULL) { 
        q->front = q->rear = temp; 
        return; 
    } 
  
    // Add the new node at the end of queue and change rear 
    q->rear->next = temp; 
    q->rear = temp; 
} 
  
// Function to remove a key from given queue q 
void deQueue(struct Queue* q) 
{ 
    // If queue is empty, return NULL. 
    if (q->front == NULL) 
        return; 
  
    // Store previous front and move front one node ahead 
    struct QNode* temp = q->front; 
  
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) 
        q->rear = NULL; 
  
    free(temp); 
} 

bool canFinish(int numCourses, int **prerequisites, int prerequisitesSize,int* prerequisitesColSize){
    int n=numCourses;
    struct List* list[n];
    int indeg[n];
    for(int i=0;i<n;i++)
    {
      indeg[i]=0;
    }
    for(int i=0;i<prerequisitesSize;i++)
    {
      int u=prerequisites[i][0];
      int v=prerequisites[i][1];

      list[v]=newedge(list[v],u);
      indeg[u]++;
    }
    struct Queue* q = createQueue(); 
    struct List *temp = (struct List *) malloc (sizeof (struct List));
    for(int i=0;i<n;i++)
    {
      if(indeg[i]==0)
      {
	      enQueue(q,i);
      }
    }
    int count=0;
    while(q->front)
    {
      temp = list[q->front->key];
      count++;
      deQueue(q);
      while(temp)
	    {
        int k=temp->i;
        indeg[k]--;
        if(indeg[k]==0)
        {
          enQueue(q,temp->i);
        }
	     temp = temp->next;
	    }
    }
    printf("%d",count);
    if(count==n) return true;
    else return false;
  }
// int main()
// {
//   int numcourses=3;
// 	int m = 2;
// 	int n = 2;
// 	int **prereq = (int **)malloc(m * sizeof(int *));
// 	for (int r = 0; r < m; r++)
// 		prereq[r] = (int *)malloc(n * sizeof(int));  
//   prereq[0][0]=0;
//   prereq[0][1]=1;
//   prereq[1][0]=1;
//   prereq[1][1]=0;
//   int prereqsize=2;
//   canFinish(numcourses,prereq,prereqsize);
// }