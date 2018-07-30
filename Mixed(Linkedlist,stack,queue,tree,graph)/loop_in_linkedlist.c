#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start1;

void display(struct node * start)
{
	struct node * ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d-->",ptr->data);
		ptr=ptr->next;
	}
void insert_end(struct node *start,int n)
{
	struct node *ptr,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	
	temp->data=n;
	temp->next=NULL;
	ptr->next=temp;
}
struct node * create(struct node *start)
{
	struct node *ptr,*ptr1;
	bool s=true;
	while(s)
	{
		int n,b;
		printf("Enter the value for the node::");
		scanf("%d",&n);
		if(start==NULL)
		{
		    struct node *temp;
		    temp=(struct node *)malloc(sizeof(struct node));
			temp->data=n;
			temp->next=NULL;
			start=temp;
		}
		else
		{
			insert_end(start,n);
		}
		printf("More nodes\n press 1:for node\n press 2:for exit:\n");
		scanf("%d",&b);
		system("cls");
		switch(b)
		{
			case 1:
			{
				break;
			}
			case 2:
			{
				s=false;
				break;
			}
		}
	}
	display(start);
	ptr=start;
	ptr1=ptr;
	while(ptr->next!=NULL)
	{
	    ptr=ptr->next;
	}
	int i;
	for(i=1;i<4;i++)
	{
	    ptr1=ptr1->next;
	}
	ptr->next=ptr1;
	return start;
}
void loop()
{
	struct node *s,*f;
	s=start1;
	f=start1;
	while(f!=NULL)
	{
		s=s->next;
		f=f->next->next;
		if(f==s)
		{	
			printf("\n loop present in the list::\n");
			break;
		}
	}
	s=start1;
	while(f!=s)
	{
		f=f->next;
		s=s->next;
	}
	printf("\n Loop node is %d ",s->data);
}

int main()
{
	start1=create(start1);
	//highest(start1);
	loop();
	//infinte loop 
	//display(start1);
	return 0;
}





