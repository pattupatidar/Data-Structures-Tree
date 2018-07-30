#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next,*random;
}*start,*start1;
struct node * create(struct node *,int);
void display(struct node *);
void copy(); 
void copy_random();
int main()
{
	int choice;
	int data;
	while(1)
	{
		printf("\n Press 1 for insertion:\n");
		printf("\n Press 2 for Display:\n");
		printf("\n Press 3 for copy elements to another list:\n");
		printf("\n Press 4 for copy_random :\n");
		printf("\n Press 5 for Exit:\n");
		printf("\n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n Enter data for node : ");
				scanf("%d",&data);
				start = create(start,data);
				break;
			case 2:
				display(start);
				break;
			case 3:
				printf("\n Copy data to the another linked list \n");
				copy();
				break;
			case 4:
				copy_random();
				break;
			case 5:
				exit(1);
		}
	}
}
struct node * create(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=data;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		struct node *ptr;
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=temp;
	}
	return start;
}
void display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\n Linked list is empty:; \n");
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("%d-->",ptr->data);
			ptr=ptr->next;
		}
		printf("->NULL");
	}
}
void copy()
{
	struct node *ptr,*ptr1;
	ptr1=start;
	while(ptr1!=NULL)
	{
		start1 = create(start1,ptr1->data);
		ptr1=ptr1->next;
	}
	display(start1);
}
void copy_random()
{
	struct node *ptr,*ptr1;
	ptr=start;
	ptr1=start1;
	while(ptr1!=NULL)
	{
		ptr1->random = ptr;
		ptr->next=ptr1;
		ptr=ptr->next;
		ptr1=ptr1->next;
	}
	printf("\n ====%d===== ",start1->random->data);
	printf("\n %d",start->next->data);
}
