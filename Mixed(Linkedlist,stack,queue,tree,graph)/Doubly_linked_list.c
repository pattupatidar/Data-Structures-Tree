#include<stdio.h>
#include<stdlib.h>
struct node 
{
	struct node *pre,*next;
	int data; 
}*start;
struct node * create(struct node *start,int data)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	if(start==NULL)
	{
		temp->pre=NULL;
		temp->next=NULL;
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
		temp->next=NULL;
		temp->pre= ptr;
		ptr->next=temp;
	}
	return start;
}
struct node * Circular(struct node *start)
{
	struct node *ptr;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
		
	}
	ptr->next=start;
	return start;
}
struct node *find_middle(struct node *start)
{
	struct node *ptr;
	int count=0;
	ptr=start;
	while(ptr->next!=start)
	{
		count++;
		ptr=ptr->next;
	}
	count++;
	printf("\n value of count is %d ",count);
	ptr=start;
	int i;
	for(i=1;i<count/2;i++)
	{
		ptr=ptr->next;
	}
	return ptr;
}
void Display(struct node *start)
{
	struct node *ptr;
	ptr=start;
	if(start==NULL)
	{
		printf("\n DLL is empty\n");
	}
	else
	{
		while(ptr->next!=start)
		{
			printf("%d->",ptr->data);
			ptr=ptr->next;
		}
		printf("%d->",ptr->data);
	}
}
int main()
{
	start=create(start,1);
	start=create(start,2);
	start=create(start,3);
	start=create(start,4);
	start=create(start,5);
	start=create(start,6);
	start = Circular(start);
	printf("\n circular linked list is :\n");
	Display(start);
	printf("\n Middle element of list is %d",find_middle(start)->data);
	return 0;
}
