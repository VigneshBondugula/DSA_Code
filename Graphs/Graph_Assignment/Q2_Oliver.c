//Algo - Using finish time and discovery time obtained from DFS. 
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List
{
  int i;
  struct List *next;
};



struct List* newedge (struct List *node, int i)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->next = node;
  return temp;
}

void
iDFS (struct List *list[], int s, int n ,int d[], int f[])
{
  bool V[n];
  int Phi[n], i, c = 1;
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
      f[i] = 0;
    }

  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  Phi[s] = -1;
  struct List *temp, *t1, *h1;
  while (head)
    {
    if (!V[head->i])
	    {
	        V[head->i] = true;
	        temp = list[head->i];
	        d[head->i] = c++;
	        if (temp)
	        {
	            h1 = head;
	            // head = head->next;
	            while (temp)
		        {
		            if (!V[temp->i])
		            {
		                head = newedge (head, temp->i);
                        Phi[temp->i] = h1->i;
                    }
                temp = temp->next;
		        }
	        }
            else
	        {
	        if (!f[head->i])
		        f[head->i] = c++;
	            head = head->next;
	        }
	    }
      else
	    {
	    if (!f[head->i])
	        f[head->i] = c++;
	    head = head->next;
	    }
    }
//   printf (" \n DFS Tree from %d is\n", s);


//   for (i = 0; i < n; ++i)
//     printf ("(%d,%d,%d,%d)\n", Phi[i]+1, i+1,d[i],f[i]);

}


int main()
{
    int N,i;
    scanf("%d",&N);
    struct List* list[N-1];
    for(i=0;i<N;i++)
    {
        list[i]=NULL;
    }
    for(i=0;i<N-1;i++)
    {
        int A,B;
        scanf("%d %d",&A,&B);
        list[A-1]=newedge(list[A-1],B-1);
        list[B-1]=newedge(list[B-1],A-1);
    }
    // iDFS(list,5,N);
    int Q;
    scanf("%d",&Q);
    int d[N],f[N];
    iDFS(list,0,N,d,f);
    for(i=0;i<Q;i++)
    {
        int C,X,Y;
        scanf("%d %d %d",&C,&X,&Y);
        if(C==0)
        {
            if(d[X-1]<d[Y-1] && f[X-1]>f[Y-1])
            {
                printf("YES\n");
            }
            else printf("NO\n");
        }
        else
        {
            if(d[X-1] > d[Y-1] && f[X-1] < f[Y-1])
            {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
}