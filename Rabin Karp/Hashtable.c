#include<stdio.h>
#include<stdlib.h>
#define H 99929
struct node
{
    int data;
    struct node* next;
};
struct node* hash_table[H]; 

void create_hashtable()
{
    for(long int i=0;i<H;i++)
    {
        struct node* head=(struct node*)malloc(sizeof(struct node));
        head->data=0;
        head->next=NULL;
        hash_table[i]=head;
    }
}
void insert(int k,int hN)
{
    struct node* hashed_value=(struct node*)malloc(sizeof(struct node));
    hashed_value->data=k;
    hashed_value->next=NULL;
    struct node* head=hash_table[hN];
    while(hash_table[hN]->next!=NULL)
    {
        hash_table[hN]=hash_table[hN]->next;
    }
    hash_table[hN]->next=hashed_value;
    hash_table[hN]=head;
}

int main()
{
    int values[3][4];
    int T[100];
    char n;
	int index,num,y,j,N,hN,hy,k=0;
	int len1=0,len2=0,i=0;
    struct node* head;
    create_hashtable();
	FILE* fp;
	fp=fopen("stringsh","r"); 
	while((n=fgetc(fp))!='\n')
	{
        num=(int)n-'0';
		T[len1]=num;
		len1++;
	}
    while(k<3)
    {
        len2=0;
        while((n=fgetc(fp))!='\n')
	    {
            num=(int)n-'0';
		    values[k][len2]=num;
		    len2++;
	    }
        N=values[k][0];
        for(i=1;i<len2;i++)
            {
                N=(2*N+values[k][i]);
            }
        hN=N%H;
        insert(k,hN);
        k++;
    }
	fclose(fp);
    //Converting y to integers
    y=T[0];
    num=2;
    for(i=1;i<len2;i++)
        {
            num*=2;
            y=2*y+T[i];
        }


    hy=y%H;
    head=hash_table[hy];
    while(hash_table[hy]->next!=NULL)
    {
        index=hash_table[hy]->next->data;
        for(i=0;i<len2;i++)
        {
            if(values[index][i]!=T[i])
            {break;}
        }
        if(i==len2)
        {
            printf("The string %d matches at index 1\n",index+1);
        }            
        hash_table[hy]=hash_table[hy]->next;
    }
    hash_table[hy]=head;

     //Shifting y to right stepwise
    for(i=1;i<=len1-len2;i++)
    {
        hy=hy*2+(T[i+len2-1]-num*T[i-1])%H;
        head=hash_table[hy];
        while(hash_table[hy]->next!=NULL)
        {
            index=hash_table[hy]->next->data;
            for(j=0;j<len2;j++)
            {
                if(values[index][j]!=T[i+j])
                {break;}
            }
            if(j==len2)
            {
                printf("The string %d matches at index %d\n",index+1,i+1);
            }
            hash_table[hy]=hash_table[hy]->next;
        }
        hash_table[hy]=head;
    }

    // for(i=0;i<len1;i++)
    // {
    //     printf("%d",T[i]);
    // }
    // printf("\n");

    // for(k=0;k<3;k++)
    // {
    // for(i=0;i<len2;i++)
    // {
    //     printf("%d",values[k][i]);
    // }
    // }
    // printf("\n%d   %d",hN,hy);
}