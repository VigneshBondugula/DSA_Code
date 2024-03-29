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



struct List *
newedge (struct List *node, int i, float w)
{
  struct List *temp = (struct List *) malloc (sizeof (struct List));
  temp->i = i;
  temp->w = w;
  temp->next = node;
  return temp;
}

void
BFS (struct List *list[], int s, int n)
{
  bool V[n];
  int Phi[n], i;

  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
    }
  struct List *head = (struct List *) malloc (sizeof (struct List));
  head->i = s;
  head->next = NULL;
  V[s] = true;
  Phi[s] = -1;
  struct List *tail = head, *temp;
  while (head)
    {
      temp = list[head->i];
      while (temp)
	{
	  if (!V[temp->i])
	    {
	      tail->next = (struct List *) malloc (sizeof (struct List));
	      tail = tail->next;
	      tail->i = temp->i;
	      tail->next = NULL;
	      V[temp->i] = true;
	      Phi[temp->i] = head->i;
	    }
	  temp = temp->next;
	}
      head = head->next;
    }
  printf (" \n BFS from %d is\n", s);

  for (i = 0; i < n; ++i)
    printf ("(%d,%d)", Phi[i], i);

}

void
DFS (struct List *list[], int s, int n)
{
  bool V[n];
  int Phi[n], i;
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      V[i] = false;
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

	  if (temp)
	    {
	      h1 = head;
	      head = head->next;
	      while (temp)
		{
		  if (!V[temp->i])
		    {
		      head = newedge (head, temp->i, 0);

		      Phi[temp->i] = h1->i;

		    }


		  temp = temp->next;
		}


	    }
	  else
	    head = head->next;
	}
      else
	head = head->next;

    }
  printf (" \n DFS Tree from %d is\n", s);


  for (i = 0; i < n; ++i)
    printf ("(%d,%d)", Phi[i], i);

}

void
MaxBottomupheapify (float H[], int A[], int B[], int i)
{
  int p = (i - 1) / 2, t;
  float temp;

  while (p > -1)
    {
      if (H[i] > H[p])
	{
	  temp = H[i];
	  H[i] = H[p];
	  H[p] = temp;
	  t = A[i];
	  A[i] = A[p];
	  A[p] = t;
	  B[A[p]] = p;
	  B[A[i]] = i;
	  i = p;
	  p = (i - 1) / 2;

	}

      else
	p = -1;
    }

}

void
MaxTopdownheapify (float H[], int A[], int B[], int i, int n)
{
  int c, t;
  float temp;

  while (2 * i + 2 < n)
    {

      if (H[2 * i + 1] > H[2 * i + 2])
	c = 2 * i + 1;
      else
	c = 2 * i + 2;
      if (H[i] < H[c])
	{
	  temp = H[i];
	  H[i] = H[c];
	  H[c] = temp;
	  t = A[i];
	  A[i] = A[c];
	  A[c] = t;
	  B[A[i]] = i;
	  B[A[c]] = c;
	  i = c;
	}

      else
	i = n;
    }
  c = 2 * i + 1;
  if (c < n & H[i] < H[c])
    {
      temp = H[i];
      H[i] = H[c];
      H[c] = temp;
      t = A[i];
      A[i] = A[c];
      A[c] = t;

      B[A[i]] = i;
      B[A[c]] = c;
      i = c;
    }

}

void
MaxAdd (float H[], int A[], int B[], float X, int *n)
{

  H[*n] = X;
  A[*n] = *n;
  B[A[*n]] = *n;
  *n = *n + 1;

  MaxBottomupheapify (H, A, B, *n - 1);
}

void
DeleteMax (float H[], int A[], int B[], int *n)
{
  int t1;
  float t;
  *n = *n - 1;
  t = H[0];
  H[0] = H[*n];
  H[*n] = t;
  t1 = A[0];
  A[0] = A[*n];
  A[*n] = t1;
  B[A[0]] = 0;
  B[A[*n]] = *n;
  MaxTopdownheapify (H, A, B, 0, *n);
}

void
MaxBuildHeap (float H[], int A[], int B[], int n)
{

  int i = n / 2;
  while (i > -1)
    {
      MaxTopdownheapify (H, A, B, A[i--], n);
    }

}

void
Bottomupheapify (float H[], int A[], int B[], int i)
{
  int p = (i - 1) / 2, t;
  float temp;

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

      else
	p = -1;
    }

}

void
Topdownheapify (float H[], int A[], int B[], int i, int n)
{
  int c, t;
  float temp;

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

      else
	i = n;
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
Add (float H[], int A[], int B[], float X, int *n)
{

  H[*n] = X;
  A[*n] = *n;
  B[A[*n]] = *n;
  *n = *n + 1;

  Bottomupheapify (H, A, B, *n - 1);
}

void
DeleteMin (float H[], int A[], int B[], int *n)
{
  float t;
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

void
BuildHeap (float H[], int A[], int B[], int n)
{

  int i = n / 2;
  while (i > -1)
    {
      Topdownheapify (H, A, B, i--, n);

    }

}

void
DecreaseKey (float H[], int A[], int B[], int i, float X)
{

  H[i] = X;

  Bottomupheapify (H, A, B, i);


}

void
IncreaseKey (float H[], int A[], int B[], int i, float X)
{

  H[i] = X;

  MaxBottomupheapify (H, A, B, i);


}

void
Dijkstra (struct List *list[], int s, int n)
{
  int A[100000], B[100000];
  struct List *node;
  float H[100000];
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
  printf (" \n The shortest path from %d is\n", s);
  for (i = 0; i < n; ++i)
    printf (" %d %f %d", i, H[B[i]], Phi[i]);


}

void
PrimsMin (struct List* list[], int s, int n)
{
  int A[100000], B[100000];
  struct List *node;
  float H[100000], mst = 0;
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
	  if (!V[v] && H[B[v]] > node->w)
	    {
	      DecreaseKey (H, A, B, B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  for (i = 0; i < n; ++i)
    mst += H[B[i]];

  printf (" \n Minimim Spanning Tree is %f\n", mst);
  for (i = 0; i < n; ++i)

    printf (" %d %f %d", i, H[B[i]], Phi[i]);


}

void
PrimsMax (struct List *list[], int s, int n)
{
  int A[100000], B[100000];
  struct List *node;
  float H[100000], mst = 0;
  int i, u, v, m = n;
  bool V[n];
  int Phi[n];
  for (i = 0; i < n; ++i)
    {
      Phi[i] = -2;
      H[i] = INT_MIN;
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
  for (i = 0; i < n && H[0] > INT_MIN; ++i)
    {
      u = A[0];
      V[u] = true;
      node = list[u];
      DeleteMax (H, A, B, &m);
      while (node)
	{
	  v = node->i;
	  if (!V[v] && H[B[v]] < node->w)
	    {
	      IncreaseKey (H, A, B, B[v], node->w);
	      Phi[v] = u;
	    }
	  node = node->next;
	}
    }
  for (i = 0; i < n; ++i)
    mst += H[B[i]];

  printf (" \n Maximum Spanning Tree is %f\n", mst);
  for (i = 0; i < n; ++i)

    printf (" %d %f %d", i, H[B[i]], Phi[i]);


}

void
main ()
{
  int A[100000], B[100000], n = 6, m, i, j, k;
  float H[100000];
  bool AM[1000][1000];


  struct List *list[n], *temp, *list1[n];
  for (i = 0; i < n; ++i)
    list[i] = NULL;
  for (i = 0; i < n; ++i)
    for (k = 0; k < n / 2; ++k)
      {
	j = rand () % n;
	if (!AM[i][j] & i != j)
	  {
	    AM[i][j] = true;
	    list[i] = newedge (list[i], j, i * j * 2.23 + 1);
	    ++m;
	    printf ("(%d %d %f)", i, j, i * j * 2.23 + 1);
	  }
      }

  printf ("\n%d\n", m);
  Dijkstra (list, 0, n);
  BFS (list, 0, n);
  DFS (list, 0, n);
  printf ("\n%d\n", m);

  m = 0;
  for (i = 0; i < n; ++i)
    {
      j = rand () % n;
      while (j < n)
	{
	  if (i == j)
	    j++;
	  list1[i] = newedge (list1[i], j, i * j * 2.23 + 1);
	  list1[j] = newedge (list1[j], i, i * j * 2.23 + 1);

	  ++m;
	  printf ("(%d %d %f)", i, j, i * j * 2.23 + 1);
	  j += rand () % n + 1;
	}
    }
  printf ("\n%d\n", m);
  Dijkstra (list1, 0, n);
  PrimsMin (list1, 0, n);
  PrimsMax (list1, 0, n);
}

