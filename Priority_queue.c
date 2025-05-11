#include<stdio.h>
int f=0,r=-1,N;
struct PriorityQueue
{
	int ele;
	int priority;
}pq[100];
void insert(int item,int prior)
{ 	
	if(r==(N-1))
	printf("Queue FULL \n");
	else
	{
		r=r+1;
		pq[r].ele=item;
		pq[r].priority=prior;
	}
}
void delete()
{ 
	if((f==0)&&(r==-1))
		printf("Queue EMPTY \n");
	else
	{
		printf("DELETE \n");
		printf("Element : %d \n",pq[f].ele);
		printf("Priority : %d \n",pq[f].priority);
		if(f==r)
		{
			f=-0;
			r=-1;
		}
		else
		{
			f=f+1;
		}
	}
}
void sort()
{
	int i,j,temp,temp1;
	for(i=f;i<r;i++)
	{
		for(j=f;j<r;j++)
		{ 	
			if(pq[j].priority>pq[j+1].priority)
			{
			temp=pq[j].ele;
			temp1=pq[j].priority;
			pq[j].ele=pq[j+1].ele;	
			pq[j].priority=pq[j+1].priority;
			pq[j+1].ele=temp;
			pq[j+1].priority=temp1;
			}
		}
	}
}
void display()
{
	int i;
	if(f==0&&r==-1)
	printf("EMPTY \n");
	else
	{
	for(i=f;i<=r;i++)
	{
		printf(" Element : %d	Priority : %d \n",pq[i].ele,pq[i].priority);
	}
	}
}
void main()
{
	int ch,item,prior;
	printf("Enter size of Priority Queue \n");
	scanf("%d",&N);
	printf("Press 1 for insert \n");
	printf("Press 2 for delete \n");
	printf("Press 3 for display \n");
	printf("Press 4 for exit \n");
	do
	{
		printf("Enter your choice \n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("Enter element and priority \n");
			scanf("%d%d",&item,&prior);
			insert(item,prior);
			break;
		case 2: sort();
			delete();
			break;
		case 3: sort();
			display();
			break;
		case 4: printf("EXITING PROGRAM \n");
			break;
		default : printf("Invalid choice \n");
		}
	}while(ch!=4);
}

