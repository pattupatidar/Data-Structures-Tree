#include<stdio.h>
#include<malloc.h>
struct Queue
{
	int front;
	int rear;
	int capacity;
	int *array;
};
struct Queue * Queue(int size)
{
	struct Queue *Q = malloc(sizeof(struct Queue));
	if(!Q)
	{
		printf("\n Memory Error!");
		return NULL;
	}
	Q->capacity = size;
	Q->front = Q->rear = -1;
	Q->array = malloc(Q->capacity * sizeof(int));
	if(!Q->array)
	{
		printf("\n Memmory Error while assigning memory to the Array!");
		return NULL;
	}
	return Q;
}
int IsEmptyQueue(struct Queue *Q)
{
	return (Q->front == -1);
}
int IsFullQueue(struct Queue *Q)
{
	int i = (Q->rear+1)%Q->capacity == Q->front;
	return i;
}
int QueueSize(struct Queue *Q)
{
	return (Q->capacity-Q->front+Q->rear+1)%Q->capacity;
}
void Enqueue(struct Queue *Q,int data)
{
	if(IsFullQueue(Q))
	{
		printf("\n Overflow!!!");
	}
	else
	{
		Q->rear = (Q->rear+1)%Q->capacity;
		Q->array[Q->rear] = data;
		if(Q->front == -1)
		{
			Q->front = Q->rear;
		}
	}
}
int Dequeue(struct Queue *Q)
{
	int data = 0;
	if(IsEmptyQueue(Q))
	{
		printf("\n Underflow!!!");
		return;
	}
	else
	{
		data = Q->array[Q->front];
		if(Q->front == Q->rear)
		{
			Q->front = Q->rear = -1;
		}
		else
		{
			Q->front = (Q->front+1)%Q->capacity;
		}
	}
	return data;
}
void DeleteQueue(struct Queue *Q)
{
	if(Q)
	{
		if(Q->array)
		{
			free(Q->array);
		}
		free(Q);
	}
}
void Print(struct Queue *Q)
{
	if(IsEmptyQueue(Q))
	{
		printf("\n Queue is Empty");
	}
	else
	{
		int i = Q->front;
		while(i != Q->rear)
		{
			printf("%d ",Q->array[i]);
			i++;
		}		
	}
}
int main()
{
	int n;
	printf("\n Enter capacity of the Queue: ");
	scanf("%d",&n);
	struct Queue *Q1 = Queue(n);
	Enqueue(Q1,1);
	Enqueue(Q1,2);
	Enqueue(Q1,3);
	Enqueue(Q1,4);
	Enqueue(Q1,5);
	printf("\n Hello Prateek \n");
	Print(Q1);
	return 0;
}
