#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List
{
  int i;
  float w;
  struct List *next;
};


struct List* newedge (struct List *node, int i, long long int  w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void Bottomupheapify (long long int H[], int A[], int B[], int i)
{
  int p = (i - 1) / 2, t;
  long long int temp;

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

void Topdownheapify (long long int H[], int A[], int B[], int i, int n)
{
  int c, t;
  long long int temp;

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

void
Add (long long int H[], int A[], int B[], int X, int n,int m)
{

  H[n] = 0;
  A[X] = X;
  A[n] = X;
  B[A[X]] = n;
  B[n]=X;
  Bottomupheapify (H, A, B, m);
}

void DeleteMin (long long int H[], int A[], int B[], int *n)
{
  long long int t;
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

void BuildHeap (long long int H[], int A[], int B[], int n)
{
  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, A, B, i--, n);
    }
}

void
DecreaseKey (long long int H[], int A[], int B[], int i, float X)
{
  H[i] = X;
  Bottomupheapify (H, A, B, i);
}


long long int Dijkstra (struct List *list[],int n,int centers[],int K,int s)
{
  long long int H[100000];
  int B[100000];
  int A[100000];
  struct List *node;
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
      if(V[u]) continue;
      V[u] = true;
      node = list[u];
      DeleteMin (H, A, B, &m);
      while (node)
	    {
	      v = node->i;
	      if (H[B[v]] > H[B[u]] + node->w)
	      {
	        DecreaseKey (H, A, B, B[v], H[B[u]] + node->w);
	        Phi[v] = u;
	      }
	      node = node->next;
	    }
    }

  // printf (" \n The shortest path from %d is\n", s);
  // for (i = 0; i < n; ++i)
  //   printf (" %d %lld %d", i, H[B[i]], Phi[i]);  
  long long int min=INT_MAX;
  for(i=0;i<K;i++)
  {
    if(min>H[B[centers[i]-1]])
      min=H[B[centers[i]-1]];
  }
  if(min==INT_MAX) return -1;
  return min;
  
}

int main()
{
  int N,M,K,Q,i,j;
  scanf("%d %d %d %d",&N,&M,&K,&Q);
  struct List* list[N];

  for(i=0;i<N;i++)
  {
    list[i]=NULL;
  }
  for(i=0;i<M;i++)
  {
    int U,V;
    long long int W;
    scanf("%d %d %lld",&U,&V,&W);
    list[U-1]=newedge(list[U-1],V-1,W);
    list[V-1]=newedge(list[V-1],U-1,W);
  }
  int centers[K-1];
  for(i=0;i<K;i++)
  {
    scanf("%d",&centers[i]);
  }
  for(i=0;i<Q;i++)
  {
    int X;
    scanf("%d",&X);
    long long int ans=Dijkstra(list,N,centers,K,X-1);
    if(ans==INT_MAX) printf("-1\n");
    else printf("%lld\n",ans);
  }
}