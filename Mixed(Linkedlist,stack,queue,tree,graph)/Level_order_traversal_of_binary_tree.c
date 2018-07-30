#include <stdio.h>
#include <stdlib.h>
#define maxx 100

struct node {
   	int data; 
	struct node *leftChild;
   	struct node *rightChild;
};
struct node *root = NULL;
struct node *queue[maxx];
void Enqueue(struct node *);
struct node * Dequeue();
void insert_node(int);
void DeleteQueue();
void search(struct node *,int);
int front=-1,rear=-1;

struct node *stack[maxx];
int top=-1;
void push(struct node *);
struct node * pop();


void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else 
   {
      current = root;
      parent = NULL;

      while(1) 
	  { 
         parent = current;
         
		 //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;                
            
            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;

            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
}

void Enqueue(struct node *data)
{
	struct queue *temp;
	
	if(front==-1)
	{
		front=0;
	}
	rear = rear+1;
	queue[rear]=data;
}
struct node * Dequeue()
{
	if(front==-1 || front==rear+1)
	{
		printf("\n Queue is empty::\n");
		return;
	}
	struct node *temp;
	temp=queue[front];
	front=front+1;
	return temp;
}
void DeleteQueue()
{
	front=rear=-1;
	
}
int queue_empty()
{
	if(front==-1 || front==rear+1)
		return 1;
	else
		return 0;
}

void levelorder()
{
	if(root==NULL)
	{
		return;
	}
	Enqueue(root);
	int max = root->data;
	while(!queue_empty())
	{
		struct node *temp;
		temp=Dequeue();
		if(temp->data >= max)
		{
			max = temp->data;
		}
		printf("%d ",temp->data);
		if(temp->leftChild)
		{
			Enqueue(temp->leftChild);
		}
		if(temp->rightChild)
		{
			Enqueue(temp->rightChild);
		}
	}
	printf("\n maximum element of the tree is  %d ",max);
	DeleteQueue();
	
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}
void search(struct node *root,int item)
{
	if(root)
	{
		if(root->data==item)
		{
			printf("\n element found in the tree \n");
			exit;
		}
		search(root->leftChild,item);
		search(root->rightChild,item);
	}
	
}

void insert_node(int data)
{
	struct node *temp,*temp1;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->leftChild=temp->rightChild=NULL;
	if(root==NULL)
	{
		root=temp;
		return;
	}
	Enqueue(root);
	while(!queue_empty())
	{
		temp1 = Dequeue();
		if(temp1->leftChild)
		{
			Enqueue(temp1->leftChild);
			
		}
		else
		{
			temp1->leftChild = temp;
			DeleteQueue();
			return;
		}
		if(temp1->rightChild)
		{
			Enqueue(temp1->rightChild);
		}
		else
		{
			temp1->rightChild = temp;
			DeleteQueue();
			return;
		}
	}
}
void push(struct node *temp)
{
	if(top==maxx-1)
	{
		printf("\n stack is full :\n");
		return;
	}
	top=top+1;
	stack[top]=temp;
}
struct node * pop()
{
	
   if(top == -1)
      printf("\nStack is Empty!!!\n");
   else{
      struct node *temp;
      temp=stack[top];
      top=top-1;
      return temp;
   }
}

void Reverse_levelOrder()
{
	struct node *temp;
	if(root==NULL)
	{
		return;
	}
	Enqueue(root);
	while(!queue_empty())
	{
		temp = Dequeue();
		if(temp->rightChild)
		{
			Enqueue(temp->rightChild);
		}
		if(temp->leftChild)
		{
			Enqueue(temp->leftChild);
		}
		push(temp);
	}
	while(top!=-1)
	{
		printf("%d ",pop()->data);
	}
}

int main(){int i;
int choice,k;
int data;
int item;
while(1){
		printf("\n");
		printf("1.Insert\n");
		printf("2.Display by level order Traversal\n");
		printf("3. Preorder traversal\n");
		printf("4.Search for an element\n");
		printf("5.Insert an element :\n");
		printf("6.To print element in revere level order\n");
		printf("7.Exit\n");
		printf("\nEnter your choice : ");
		scanf("%d",&choice);
switch(choice)
		{
case 1:
				printf("\nEnter the key to be inserted : ");
				scanf("%d",&k);
				insert(k);
				break;
case 2:
				printf("\n");
				levelorder();
				printf("\n");
				break;
case 3:
				preorder(root);
				break;
case 4:
	    		printf("\n Enter the no that u want to search : ");
	    		scanf("%d",&item);
	    		search(root,item);
	    		break;
case 5:	
	    		printf("\n Enter the data that u want to insert :");
	    		scanf("%d",&data);
				insert_node(data);
				break;
case 6:
				Reverse_levelOrder();
				break;
case 7:
				exit(1);
				break;
default:
				printf("\nWrong choice\n");
		}
		
	}
	return 0;
}

