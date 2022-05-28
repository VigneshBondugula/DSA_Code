#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct List
{
  int i;
  long long int w;
  struct List *next;
};

struct PQ
{
    int dist;
    int i;
};
int m=0;
struct PQ* pq[100000];

struct List* newedge (struct List *node, int i, long long int w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void bottom_up_heapify(int i)
{
    int p=(i-1)/2;
    int t;
    while(p>=0 && pq[p]->dist > pq[i]->dist)
    {
        t=pq[i]->dist;
        pq[i]->dist=pq[p]->dist;
        pq[p]->dist=t;
        t=pq[i]->i;
        pq[i]->i=pq[p]->i;
        pq[p]->i=t;
        i=p;
        p=(i-1)/2;
    }
}
void top_down_heapify(int i)
{
    int l,t;
    while(2*i+2<m)
    {
        if(pq[2*i+1]->dist<pq[2*i+2]->dist) l=2*i+1;
        else l=2*i+2;
        if(pq[i]->dist>pq[l]->dist)
        {
            t=pq[i]->dist;
            pq[i]->dist=pq[l]->dist;
            pq[l]->dist=t;
            t=pq[i]->i;
            pq[i]->i=pq[l]->i;
            pq[l]->i=t;
        }
        else break;
    }
    if(2*i+1<m & pq[i]->dist>pq[2*i+1]->dist)
    {
        t=pq[i]->dist;
        pq[i]->dist=pq[2*i+1]->dist;
        pq[2*i+1]->dist=t;
        t=pq[i]->i;
        pq[i]->i=pq[2*i+1]->i;
        pq[2*i+1]->i=t;
    }
}
void add(long long int dist,int x)
{
    struct PQ* temp = (struct PQ *) malloc (sizeof (struct PQ));
    temp->dist=dist;
    temp->i=x;
    pq[m++]=temp;
    bottom_up_heapify(m-1);
}

void delete_min()
{
    pq[0]->dist=pq[--m]->dist;
    pq[0]->i=pq[--m]->i;
    top_down_heapify(0);
}

void DecreaseKey( long long int X,int i,int n)
{
   int j;
  for(j=0;j<n;j++)
  {
      if(pq[j]->i == i)
      {
          pq[j]->dist=X;
          break;
      }
  }
  bottom_up_heapify(j);
}

void Dijkstra (struct List *list[],int n,int K,int centers[],long long int H[])
{
    struct List *node;
    int i, u, v;
    bool V[n];
    int Phi[n];
    for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i]=INT_MAX;
      V[i] = false;
      add(INT_MAX,i);
    }
    for(i=0;i<K;i++)
    {
        DecreaseKey(0,centers[i]-1,n);
        H[centers[i]-1]=0;
        Phi[centers[i]-1]=-1;
    }
    while(m>0)
    {
        int u=pq[0]->i;
        delete_min();
        if(V[u]) continue;
        V[u]=true;
        node = list[u];
        while (node)
	    {
	      v = node->i;
	      if (!V[v] && H[v] > H[u] + node->w)
	      {
            H[v] = H[u] + node->w;
            DecreaseKey(H[v],v,n);
	        Phi[v] = u;
	      }
	      node = node->next;
	    }
    }
    //   printf (" \n The shortest path from %d is\n", s);
//   for (i = 0; i < n; ++i)
//     printf (" %d %lld %d\n", i+1, H[i], Phi[i]+1);  
}

int main()
{
  int N,M,K,Q,i,j;
  scanf("%d %d %d %d",&N,&M,&K,&Q);
  struct List* list[N];
  long long int H[N];
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
  Dijkstra(list,N,K,centers,H);
  for(i=0;i<Q;i++)
  {
    int X;
    scanf("%d",&X);
    if(H[X-1]==INT_MAX) printf("-1\n");
    else printf("%lld\n",H[X-1]);
  }
}