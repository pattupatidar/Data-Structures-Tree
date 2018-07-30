#include<stdio.h>
#include<conio.h>
struct table
{
	int vertex_no;
	int distance;
	int parent;
};
struct Priority_Queue
{
	int  ver;
	int priority;
};
int weight[5][5];
struct Priority_Queue PQ[5];
struct table tab[5];
int front=0,rear=-1;
int Qfull()
{
	if(rear==4)
	{
		return 1;
	}
	return 0;
}
int Qempty()
{
	if(front > rear)
	{
		return 1;
	}
	return 0;
}
void Enqueue(int item,int pri)
{
	int i;
	if(Qfull())
	{
		printf("\n Overflow \n");
	}
	else
	{
		i = rear;
		++rear;
		while(PQ[i].priority > pri && i>=0)
		{
			PQ[i+1] = PQ[i];
			i--;
		}
		PQ[i+1].ver = item;
		PQ[i+1].priority = pri;
	}
}
int Dequeue()
{
	int p;
	if(Qempty())
	{
		printf("\n Underflow!\n");
		return -1;
	}
	else
	{
		p = PQ[front].ver;
		front = front+1;
		return (p);
	}
}
void Dijekstra(int s)
{
	int v,w,i,d,j;
	Enqueue(s,0);
	for(i=0;i<5;i++)
	{
		tab[i].distance = -1;	
	}
	tab[s].distance = 0;
	while(!Qempty())
	{
		v = Dequeue();
		//printf("=========%d\n",v);
		for(w=0;w<5;w++)
		{
			if(weight[v][w]!=0)
			{
				d = tab[v].distance + weight[v][w];
				if(tab[w].distance == -1)
				{
					//printf("\n===========PP\n");
					tab[w].distance = d;
					Enqueue(w,d);
					tab[w].parent = v;	
				}
				if(tab[w].distance > d)
				{
					tab[w].distance = d;
					PQ[w].priority = d;
					tab[w].parent = v;	
				}
			}
		}	
	}	
}

int main()
{
	
	int e,we,s;
	int i,j,x,y;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			weight[i][j] = 0;
		}
	}
	printf("\n Enter no of edges : ");
	scanf("%d",&e);
	printf("\n Enter edge and weight of edge:  ");
	printf("\nSourse\tDestination\tWeight\n");
	printf("----------------------------------------------------\n");
	for(i=0;i<e;i++)
	{
		scanf("%d%d%d",&x,&y,&we);
		weight[x][y] = we;
	}
	printf("\n Entered Graph is : \n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d\t",weight[i][j]);
		}
		printf("\n");
	}
	printf("\n Enter sourse vertex : ");
	scanf("%d",&s);
	Dijekstra(s);
	printf("\n");
	printf("\nvertex\tDistance\tParent\n");
	printf("----------------------------------------------\n");
	for(i=0;i<5;i++)
	{
		printf("%d\t%d\t\t%d",i,tab[i].distance,tab[i].parent);
		printf("\n");
	}
	return 0;
}
