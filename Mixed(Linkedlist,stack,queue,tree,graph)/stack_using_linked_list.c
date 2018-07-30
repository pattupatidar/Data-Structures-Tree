#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
}*top=NULL;
void push(int);
void pop();
void display();

int main()
{
   int choice, value;
   printf("\n:: Stack using Linked List ::\n");
   while(1){
      printf("\n****** MENU ******\n");
      printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice){
	 		case 1: printf("Enter the value to be insert: ");
		 		scanf("%d", &value);
		 		push(value);
		 		break;
	 		case 2: pop(); break;
	 		case 3: display(); break;
	 		case 4: exit(0);
	 		default: printf("\nWrong selection!!! Please try again!!!\n");
      }
   }
   getch();
   return 0;
}

void push(int value)
{
	struct stack *temp;
	temp = (struct stack *)malloc(sizeof(struct stack));
	temp->data=value;
	if(top==NULL)
	{
		temp->next=NULL;
		top =temp;
	}
	else
	{
		temp->next=top;
		top=temp;
	}
}
void pop()
{
	
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct stack *temp = top;
      printf("\nDeleted element: %d",temp->data);
      top = temp->next;
      free(temp);
   }
}
void display()
{
	
   if(top == NULL)
   	{
   		printf("\nStack is Empty!!!\n");
   	}
	else
   	{
      struct stack *temp = top;
      while(temp->next!= NULL)
	  {
		  printf("%d--->",temp->data);
		  temp = temp -> next;
      }
      printf("%d--->NULL",temp->data);
    }
 
}
