#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node *next;
}*front = NULL,*rear = NULL;

void insert(int);
struct Node * delete();
void display();

void main()
{
   int choice, value;
   printf("\n:: Queue Implementation using Linked List ::\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 case 1: printf("Enter the value to be insert: ");
		 scanf("%d", &value);
		 insert(value);
		 break;
	 case 2: delete(); break;
	 case 3: display(); break;
	 case 4: exit(0);
	 default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
}
void insert()
{
	struct Node *temp;
	temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	if(front==NULL)
	{
		rear=temp;
		front=temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}
struct Node * delete()
{
	if(front==NULL)
	{
		printf("\n Queue is empty::\n");
	}
	struct Node *temp;
	temp=front;
	printf("\n Deleted element is %d",front->data);
	front=front->next;
	free(temp);
	return temp;
}
void display()
{
	struct Node *ptr;
	ptr = delete();
	printf("\n Deleted element is %d ======",ptr->data);
	/*ptr=front;
	if(front==NULL)
	{
		printf("\n Queue is empty:: \n");
	}
	while(ptr!=NULL)
	{
		printf("%d--->",ptr->data);
		ptr=ptr->next;
	}*/
}
