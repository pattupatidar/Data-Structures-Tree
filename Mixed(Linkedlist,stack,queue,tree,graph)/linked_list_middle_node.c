#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}*start,*start1,*merge_head;
struct node * create(struct node *);
void insert_end(struct node *start);
struct node * InsertFront(struct node *start);
int find_node(struct node *,int);
int middle(struct node *);
void display();
int main()
{
	int n,i,node;
	printf("\n Enter the no of nodes in the linked list1:: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		start = create(start);
	}
	display(start);
	printf("\n Enter the no of nodes in the linked list2:: \n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		start1 = create(start1);
	}
	display(start1);
	merge_head = merge(start,start1);
	display(merge_head);
	/*int mid = middle(start);
	printf("\n middle of list is %d ",mid);
	printf("\n enter number that needs to find from end : ");
	scanf("%d",&node);
	int  nn = find_node(start,node);
	printf("%d node from end is: %d",node,nn);
	*/return 0;
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
	return start;
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
void merge(struct node *start,struct node *start1)
{
	struct node *p,*q,*s;
	p = start;
	q = start1;
	if(p==NULL)
	{
		return q;
	}
	if(q==NULL)
	{
		return p;
	}
	if(p && q)
	{
		if(p->data <= q->data)
		{
			s = p;
			p = s->next;
		}
		else
		{
			s = q;
			q = s->next;
		}
	}
	merge_head = s;
	while(p && q)
	{
		if(p->data <= q->data)
		{
			s->next = p;
			s = p;
			p = s->next;
		}
		else
		{
			s->next = q;
			s = q;
			q = s->next;
		}
		if(p==NULL)
		{
			s->next = q;
		}
		if(q==NULL)
		{
			s->next = p; 
		}
	}
	return merge_head;
}
void display(struct node *st)
{
    struct node *ptr;
    ptr=st;
    if(st==NULL)
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
int middle(struct node *start)
{
	struct node *ptr,*ptr1;
	ptr = ptr1 = start;
	while(ptr && ptr->next!=NULL)
	{
		ptr = ptr->next->next;
		ptr1 = ptr1->next;
	}
	return ptr1->data;
}
int find_node(struct node *start,int node)
{
	struct node *ptr,*ptr1;
	ptr = ptr1 = start;
	while(node!=0)
	{
		ptr = ptr->next;
		node--;
	}
	while(ptr!=NULL)
	{
		ptr =ptr->next;
		ptr1 = ptr1->next;
	}
	return ptr1->data;
}
