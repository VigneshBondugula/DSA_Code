#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct BST
{
  long long int key;
  int height;
  long long int max, high;
  struct BST *left, *right;
};

struct BST* newNode (long long int l, long long int r)
{
  struct BST *temp = (struct BST *) malloc (sizeof (struct BST));
  temp->key = l;
  temp->max = temp->high = r;
  temp->left = temp->right = NULL;
  temp->height = 0;
  return temp;
}


int Max (int x, int y)
{
  if (x < y)
    return y;
  else
    return x;
}

int Min (int x, int y)
{
  if (x < y)
    return x;
  else
    return y;
}

int Height (struct BST *node)
{
  if(node)
    {
      if(node->left && node->right)
	return 1 + Max (node->left->height, node->right->height);
      else if (node->left)
	return 1 + node->left->height;
      else if (node->right)
	return 1 + node->right->height;
      else
	return 0;
    }
  else
    return -1;
}

void Updatemax (struct BST *node)
{
  if(node)
    {
      node->max = node->high;
      if (node->left && node->left->max > node->high) node->max = node->left->max;
      if (node->right && node->right->max > node->max) node->max = node->right->max;
    }
}

bool AVL (struct BST *node)
{
  if (abs(Height(node->left) - Height (node->right)) < 2)
    return true;
  else
    return false;
}

void Inorder (struct BST *node)
{
  if (node)
    {
      Inorder (node->left);
      printf ("(%lld,%lld)   ", node->key, node->high);
      Inorder (node->right);
    }
}

struct BST* Overlap (struct BST* node, long long int l, long long int r)
{
  while(node)
    {
      if (l <= node->high && node->key <= r) return node;
      if (node->left && node->left->max >= l) node = node->left;
      else node = node->right;
    }
  return NULL;
}

struct BST* Rotate (struct BST *Z)
{
  struct BST *X, *Y, *T1, *T2, *T3, *T4;
  int c = 0;
  if (Height (Z->left) + 1 == Z->height)
    Y = Z->left;
  else
    {
      Y = Z->right;
      c++;
    }
  c = c * 2;
  if (Height (Y->left) + 1 == Y->height)
    X = Y->left;
  else
    {
      X = Y->right;
      c++;
    }

  if (c == 0)
    {
      T3 = Y->right;
      Y->right = Z;
      Z->left = T3;
      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Updatemax (Z);
      Updatemax (X);
      Updatemax (Y);
      return Y;

    }
  else if (c == 3)
    {

      T2 = Y->left;
      Y->left = Z;
      Z->right = T2;

      Z->height = Height (Z);
      X->height = Height (X);
      Y->height = Height (Y);
      Updatemax (Z);
      Updatemax (X);
      Updatemax (Y);
      return Y;
    }
  else if (c == 1)
    {

      T2 = X->left;
      T3 = X->right;
      Y->right = T2;
      Z->left = T3;
      X->left = Y;
      X->right = Z;

      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Updatemax (Z);
      Updatemax (Y);
      Updatemax (X);
      return X;

    }
  else
    {
      T2 = X->left;
      T3 = X->right;
      Y->left = T3;
      Z->right = T2;
      X->left = Z;
      X->right = Y;

      Z->height = Height (Z);
      Y->height = Height (Y);
      X->height = Height (X);
      Updatemax (Z);
      Updatemax (Y);
      Updatemax (X);
      return X;
    }
}

struct BST* Insert (struct BST *node, long long int key, long long int r)
{
  // If the BST is empty, create a  new BST
  if (!node)
    return newNode (key, r);
  if(key == node->key)
  {
    if(node->high > r) node->left = Insert(node->left,key,r);
    else if(node->high < r) node->right = Insert(node->right,key,r);
  }
  if (key < node->key)
    node->left = Insert (node->left, key, r);
  else if (key > node->key)
    node->right = Insert (node->right, key, r);
  node->height = Height (node);
  Updatemax (node);
  if (!AVL (node))
    {
      node = Rotate (node);
    }
  return node;
}

struct BST* Delete (struct BST *node, long long int X, long long int r)
{
  if (!node)
    return node;

  if (node->key > X)
    {
      node->left = Delete (node->left, X,r);
      node->height = Height (node);
      Updatemax (node);
      if (!AVL (node))
	    node = Rotate (node);
      return node;
    }

  else if (node->key < X)
    {
      node->right = Delete (node->right, X,r);
      node->height = Height (node);
      Updatemax (node);
      if (!AVL (node))
	    node = Rotate (node);
      return node;
    }

  else
  {
    if (node->high > r)
    {
      node->left = Delete (node->left, X,r);
      node->height = Height (node);
      Updatemax (node);
      if (!AVL (node))
	    node = Rotate (node);
      return node;
    }

    else if (node->high < r)
    {
      node->right = Delete (node->right, X,r);
      node->height = Height (node);
      Updatemax (node);
      if (!AVL (node))
	    node = Rotate (node);
      return node;
    }

    if (node->left && node->right)
      {
        struct BST *temp = node->left;
        while (temp->right)
	      temp = temp->right;
        node->key = temp->key;
        node->high = temp->high;
        node->left = Delete (node->left, temp->key ,temp->high);
        Updatemax(node);
      }

    else
      {
        struct BST *child;
        if (node->left) child = node->left;
        else child = node->right;
        free (node);
        return child;
      }
  }
}

void main ()
{
  struct BST* root=NULL;
  root= Insert(root,4,6);
  root= Insert(root,3,9);
  root= Insert(root,10,11);
  root= Insert(root,4,9);
  root= Insert(root,9,10);
  root= Insert(root,3,6);
  Inorder(root);
  printf("\n");
  root= Delete(root,9,10);
  root= Delete(root,10,11);
  root= Delete(root,3,9);

  Inorder(root);
  printf("\n");
  if(Overlap(root,7,8))
    printf("(%lld,%lld)", Overlap(root,7,8) -> key ,Overlap(root,7,8) -> high);
}