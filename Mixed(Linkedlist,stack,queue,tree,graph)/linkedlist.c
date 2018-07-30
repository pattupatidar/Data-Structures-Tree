#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*start,*start1;
struct node * create(struct node *);
void insert_end(struct node *start);
struct node * InsertFront(struct node *start);
void display();
void order(struct node *start,int n)
{
	struct node *ptr,*ptr1;
	ptr=start;
	ptr1=ptr;
	int temp,i;
	for(i=1;i<=n;i++)
	{
		if(ptr->data%2==0)
		{
			ptr=ptr->next;
		}
		else
		{
			while(ptr->next!=NULL)
			{
				if(ptr->data%2==0)
				{
					break;
				}
				else
				{
					ptr=ptr->next;
				}
			}
			temp=ptr->data;
			ptr->data=ptr1->data;
			ptr1->data=temp;
		}
		ptr1=ptr1->next;
		ptr=ptr1;
	}
}
struct node * order_best(struct node *start)
{
	struct node *oddhead,*evenhead;
	struct node *lastodd,*lasteven;
	struct node *ptr;
	ptr=start;
	oddhead=NULL;
	evenhead=NULL;
	lastodd=NULL;
	lasteven=NULL;
	//printf("\n data of ptr is :%d ",ptr->data);
	while(ptr!=NULL)
	{
		if(ptr->data%2==0)
		{
			if(evenhead==NULL)
			{
				evenhead=ptr;
				lasteven=ptr;
			}
			else
			{
				lasteven->next=ptr;
				lasteven=ptr;
			}
		}
		else
		{
			if(oddhead==NULL)
			{
				oddhead=ptr;
				lastodd=ptr;
			}
			else
			{
				lastodd->next=ptr;
				lastodd=ptr;
			}
			
		}
		ptr=ptr->next;
	}
	if(evenhead!=NULL)
		start=evenhead;
	if(lasteven!=NULL)
		lasteven->next=oddhead;
	if(lastodd!=NULL)
		lastodd->next=NULL;
	return start;
}
int main()
{
	int n,i;
	printf("\n Enter the no of nodes in the linked list:: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		start = create(start);
	}
	display();
	//start = InsertFront(start);
	//display();
	//order(start,n);
	printf("\n new list is :\n");

	start=order_best(start);
	display();
	return 0;
}
struct node * create(struct node *start)
{
	if(start==NULL)
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		int d;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter Data for the node::");
		scanf("%d",&d);
		temp->data=d;
		temp->next=NULL;
		start=temp;
	}
	else
	{
		insert_end(start);
	}
}
void insert_end(struct node *start)
{
	struct node *ptr,*temp;
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		int data;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("\n Enter Data for the node::");
		scanf("%d",&data);
		temp->data=data;
		temp->next=NULL;
		ptr->next=temp;
}
struct node * InsertFront(struct node *start)
{
	int da;
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("\n Enter data for node to be inserted at begining::");
	scanf("%d",&da);
	printf("\n data of start node is %d",start->data);
	temp->data=da;
	temp->next=start;
	start=temp;
	return start;
}
void display()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\n list is empty::");
    }
    printf("\n linked list::\n");
    while(ptr!=NULL)
    {
        printf(" %d->",ptr->data);
        ptr=ptr->next;
    }
}

