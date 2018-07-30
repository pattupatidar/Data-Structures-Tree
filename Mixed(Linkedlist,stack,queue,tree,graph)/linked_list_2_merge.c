#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
};
struct node * Insert(struct node *start,int data);
void display(struct node *);
struct node * merge(struct node *start,struct node *start1)// Merge function that will merge two sorted lists
{
	struct node *ptr,*ptr1,*s = NULL,*q;
	ptr = start;
	ptr1 = start1;
	if(ptr->data >= ptr1->data)
	{
		q = s = ptr1;
		ptr1 = ptr1->next;
	}
	else
	{
		q = s = ptr;
		ptr = ptr->next;
	}
	while(ptr != NULL && ptr1 != NULL)
	{
		if(ptr->data >= ptr1->data)
		{
			s->next = ptr1;
			s = ptr1;
			ptr1 = ptr1->next;
		}
		else
		{
			s->next = ptr;
			s = ptr;
			ptr = ptr->next;
		}
	}
	while(ptr != NULL)
	{
		
		s->next = ptr;
		ptr = ptr->next;
	}
	while(ptr1 != NULL)
	{
		s->next = ptr1;
		ptr1 = ptr1->next;
	}
	return q;
}
int main()
{
	struct node *start = NULL,*start1 = NULL;
	start = Insert(start,2);
	start = Insert(start,4);
	start = Insert(start,6);
	start = Insert(start,8);
	start = Insert(start,10);
	display(start);
	start1 = Insert(start1,1);
	start1 = Insert(start1,3);
	start1 = Insert(start1,5);
	start1 = Insert(start1,7);
	start1 = Insert(start1,9);
	display(start1);
	struct node *q = merge(start,start1);
	printf("\n Merged list is : ");
	display(q);
}
struct node * Insert(struct node *start,int data)
{
	struct node *ptr,*temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	if(start == NULL)
	{
		temp->next =NULL;
		start = temp;
	}
	else
	{
		ptr = start;
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next =temp;
		temp->next = NULL;
	}
	return start;
}
void display(struct node *start)
{
	printf("\n Linked List is : ");
	struct node *ptr = start;
	while(ptr != NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
}
