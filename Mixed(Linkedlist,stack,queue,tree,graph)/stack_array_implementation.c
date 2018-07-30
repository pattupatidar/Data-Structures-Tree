#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct stack
{
	int capacity;
	int top;
	int *array;
};
int IsEmptyStack(struct stack *s)
{
	if(s->top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int IsFullStack(struct stack *s)
{
	if(s->top == s->capacity-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
struct stack * create(int capacity)
{
	struct stack *s = malloc(sizeof(struct stack));
	s->top = -1;
	s->capacity = capacity;
	s->array = malloc(capacity * sizeof(int));
	return s;	
}
void push(struct stack *s,int data)
{
	if(IsFullStack(s))
	{
		printf("\n Stack is already Full Buddy!!!");
	}
	else
	{
		s->array[++s->top] = data;
	}
}
int pop(struct stack *s)
{
	if(IsEmptyStack(s))
	{
		printf("\n Stack is Empty!!!");
	}
	else
	{
		return s->array[s->top--];
	}
}
void Print(struct stack *s)
{
	int i = s->top;
	while(i != -1)
	{
		printf("%d ",s->array[i]);
		i--;
	}
}
int main()
{
	struct stack *s1 = create(5);
	push(s1,1);
	push(s1,2);
	push(s1,3);
	push(s1,4);
	push(s1,5);
	push(s1,6);
	Print(s1);
	pop(s1);
	pop(s1);
	printf("\n");
	Print(s1);	
	return 0;
}
