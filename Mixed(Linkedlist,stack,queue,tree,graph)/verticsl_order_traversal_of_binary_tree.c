#include <stdio.h>
#include <stdlib.h>
#define maxx 10

struct node {
   	int data; 
	struct node *leftChild;
   	struct node *rightChild;
   	int hd;
};
struct node1
{
	int data;
	int hd;
	struct node1 *next;
};
struct node *root = NULL;
struct node *queue[maxx];
struct node1 *hash_table[maxx];
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
	while(!queue_empty())
	{
		struct node *temp;
		temp=Dequeue();
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
	DeleteQueue();
}
void insert_hash_table(int hd,int data)
{
	if(hash_table[abs(hd%maxx)].data==-1)
	{
		hash_table[abs(hd%maxx)].data=data;
		hash_table[abs(hd%maxx)].hd=hd;			
	}
	else
	{
		struct node1 *temp;
		temp = (struct node1 *)malloc(sizeof(struct node1));
		temp->next=NULL;
		temp->data=data;
		hash_table[abs(hd%maxx)].next=temp;	
	}	
}
void display(struct node1 hash_table[])
{
	int i;
	printf("\n");
	printf("value\tkey");
	for(i=0;i<maxx;i++)
	{
		printf("\n%d\t%d",hash_table[i].data,hash_table[i].hd);
		struct node1 *ptr;
		ptr=hash_table[i].next;
		if(ptr!=NULL)
		{
			printf("->%d",ptr->data);
			ptr=ptr->next;
		}
	}
}
void vertical_order_traversal()
{
	struct node *temp;
	if(root==NULL)
	{
		return;
	}
	Enqueue(root);
	root->hd = 0;
	while(!queue_empty())
	{
		temp = Dequeue();
		if(temp->leftChild)
		{
			temp->leftChild->hd = temp->hd-1;
			Enqueue(temp->leftChild);
		}
		if(temp->rightChild)
		{
			temp->rightChild->hd = temp->hd+1;
			Enqueue(root->rightChild);
		}
		insert_hash_table(temp->hd,temp->data);
	}
}
void assign_value()
{
	int i;
	i=0;
	while(i<maxx)
	{
		hashtable[i].data=-1;
		hashtable[i].next=NULL;
		i++;
	}
}
void display()
{
	int i;
	printf("\ntable is ::\n");
	printf("\nvalue\n");
	for(i=0;i<maxx;i++)
	{
		printf("%d",hash_table.data);
		struct node *ptr;
		ptr=hash_table.rightChild;
		while(ptr!=NULL)
		{
			printf("->%d",ptr->data);
			ptr=ptr->rightChild;	
		}
		printf("\n");
	}
}

int main(){
int i;
assign_value();
int choice,k;
int data;
int item;
while(1){
		printf("\n");
		printf("1.Insert\n");
		printf("2.Display by level order Traversal\n");
		printf("3. Vertical order traversal\n");
		printf("4.Exit\n");
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
				vertical_order_traversal();
				Display();
				break;
case 4:
				exit(1);
				break;
default:
				printf("\nWrong choice\n");
		}
	}
	return 0;
}

