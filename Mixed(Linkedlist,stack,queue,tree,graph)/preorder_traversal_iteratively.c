#include <stdio.h>
#include <stdlib.h>

struct node 
{
   	int data; 
	struct node *leftChild;
  	struct node *rightChild;
};
struct node *root = NULL;

struct stack
{
	int data;
	struct stack *next;
}*top=NULL;

void push(int);
struct stack * pop();


void insert(int data) 
{
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) { 
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

void pre_order_traversal(struct node* root)
{
	while(1)
	{
		while(root)
		{
			printf("%d ",root->data);
			push(root->data);
			root->leftChild;	
		}
		if(IsEmptyStack(top))
			break;	
		root=pop();
		root=root->rightChild;
	}	   
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);          
      inorder_traversal(root->rightChild);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);
   }
}
int main() 
{
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };
	for(i = 0; i < 7; i++)
      insert(array[i]);
	

  printf("\nPreorder traversal: ");
   pre_order_traversal(root);

/*   printf("\nInorder traversal: ");
   inorder_traversal(root);

   printf("\nPost order traversal: ");
   post_order_traversal(root);       
*/
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
struct stack * pop()
{
	
   if(top == NULL)
      printf("\nStack is Empty!!!\n");
   else{
      struct stack *temp = top;
      printf("\nDeleted element: %d",temp->data);
      top = temp->next;
      //free(temp);
      return temp; 
	}
}

