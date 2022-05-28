//Algo - Dijkstras algo
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List
{
  int i;
  int w;
  struct List *next;
};


struct List* newedge (struct List *node, int i, int  w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void Bottomupheapify (int H[], int A[], int B[], int i)
{
  int p = (i - 1) / 2, t;
  int temp;
  while (p > -1)
    {
      if (H[i] < H[p])
	      {
	        temp = H[i];
	        H[i] = H[p];
	        H[p] = temp;
	        t = A[i];
	        A[i] = A[p];
	        A[p] = t;
	        B[A[i]] = i;
	        B[A[p]] = p;
	        i = p;
	        p = (i - 1) / 2;
        }
      else p = -1;
    }
}

void Topdownheapify (int H[], int A[], int B[], int i, int n)
{
  int c, t;
  int temp;

  while (2 * i + 2 < n)
  {
    if (H[2 * i + 1] < H[2 * i + 2])
	    c = 2 * i + 1;
    else
	    c = 2 * i + 2;
    if (H[i] > H[c])
	  {
	    temp = H[i];
	    H[i] = H[c];
	    H[c] = temp;
	    t = A[i];
	    A[i] = A[c];
	    A[c] = t;
	    B[A[c]] = c;
	    B[A[i]] = i;
	    i = c;
	  }
    else i = n;
  }
  c = 2 * i + 1;
  if (c < n & H[i] > H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      t = A[i];
      A[i] = A[c];
      A[c] = t;

      B[A[c]] = c;
      B[A[i]] = i;
      i = c;
    }
}

void DeleteMin (int H[], int A[], int B[], int *n)
{
  int t;
  int t1;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  t1 = A[0];
  A[0] = A[*n];
  A[*n] = t1;
  B[A[0]] = 0;
  B[A[*n]] = *n;
  Topdownheapify (H, A, B, 0, *n);
}

void BuildHeap (int H[], int A[], int B[], int n)
{
  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, A, B, i--, n);
    }
}

void
DecreaseKey (int H[], int A[], int B[], int i, int X)
{
  H[i] = X;
  Bottomupheapify (H, A, B, i);
}


int Dijkstra (struct List *list[], int s, int n)
{
  int A[100000], B[100000];
  struct List *node;
  int H[100000];
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i] = INT_MAX;
      A[i] = i;
      B[i] = i;
      V[i] = false;
    }

  H[0] = 0;
  Phi[s] = -1;
  A[0] = s;
  A[s] = 0;
  B[0] = s;
  B[s] = 0;
  for (i = 0; i < n && H[0] < INT_MAX; ++i)
    {
      u = A[0];
      V[u] = true;
      node = list[u];
      DeleteMin (H, A, B, &m);
      while (node)
	    {
	      v = node->i;
	      if (!V[v] && H[B[v]] > H[B[u]] + node->w)
	      {
	        DecreaseKey (H, A, B, B[v], H[B[u]] + node->w);
	        Phi[v] = u;
	      }
	      node = node->next;
	    }
    }
  // printf (" \n The shortest path from %d is\n", s);
  // for (i = 0; i < n; ++i)
  //   printf (" %d %d %d", i, H[B[i]], Phi[i]); 
  return H[B[n-1]];
  }  

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        struct List* list[n-1];
        int P[n];
        for(int j=0;j<n;j++)
        {
          list[j]=NULL;
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d ",&P[j]);
        }
        for(int j=0;j<n;j++)
        {
            list[j]=newedge(list[j],P[j]-1,0);
            if(j>0) list[j]=newedge(list[j],j-1,1);
            if(j<n) list[j]=newedge(list[j],j+1,1);
        }
        printf("%d\n",Dijkstra(list,0,n));
        for(int j=0;j<n;j++)
        {
          free(list[j]);
        }
    }   
}