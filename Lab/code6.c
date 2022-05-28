#include<stdio.h>
int validateStacksequences(int pushed[],int popped[])
{
	int S[5],i=0,j=0;
	int top=-1;
	S[++top]=pushed[0];
	i++;
	while(i<=5 && j<5)
	{
		if(S[top]==popped[j])
		{
			top--;
			j++;
		}
		else
		{
			S[++top]=pushed[i];
			i++;
		}
	}
	if(top!=-1)
	{
		return 0;
	}
	return 1;
}
int main()
{
	int pushed[5]={1,2,3,4,5},popped[5]={4,5,3,2,1};
	printf("%d",validateStacksequences(pushed,popped));
}