#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct stack
{
	int top;
	int capacity;
	int *array;
};
// Tree insertion code
struct node * GetNewNode(int data)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if(!temp)
	{
		printf("Memory Error");
		return NULL;
	}
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}
struct node * Insert(struct node *root,int data)
{
	if(root == NULL)
	{
		root = GetNewNode(data);
	}
	else
	{
		if(data <= root->data)
		{
			root->left = Insert(root->left,data);
		}
		else
		{
			root->right = Insert(root->right,data);
		}
	}
	return root;
}
//stack Implementation code
struct stack * create(int capacity)
{
	struct stack *s1 = malloc(sizeof(struct stack));
	if(!s1)
	{
		printf("!!! Memory Error ");
		return;
	}
	s1->capacity = capacity;
	s1->top = -1;
	s1->array = malloc(capacity * sizeof(int));
	if(!s1->array)
	{
		printf("!!! Memory Error while assigning to array");
		return;
	}
	return s1;
}
void push(struct stack *s,int data)
{
	if(s->top == s->capacity-1)
	{
		printf("\n Overflow!!!");
	}
	else
	{
		s->array[++s->top] = data;
	}
}
int pop(struct stack *s)
{
	if(s->top == -1)
	{
		printf("\n Underflow!!!");
		return;
	}
	else
	{
		int temp = s->array[s->top--];
		return temp;
	}
}
void Delete_stack(struct stack *s)
{
	if(s)
	{
		if(s->array)
		{
			free(s->array);	
		}
		free(s);	
	}	
}
int IsEmptyStack(struct stack *s)
{
	if(s->top == -1)
	{
		return 1;	
	}	
	else
	{
		return 0;
	}
}
void Zig_Zag(struct node *root,struct stack *s1,struct stack *s2)
{
	if(root == NULL)
	{
		printf("\n No Elements to process: ");
		return;
	}
	else
	{
		push(s1,root);
		while(1)
		{
			while(!IsEmptyStack(s1))
			{
				struct node *temp = pop(s1);
				printf("%d ",temp->data);
				if(temp->left)
				{
					push(s2,temp->left);	
				}
				if(temp->right)
				{
					push(s2,temp->right);	
				}	
			}
			while(!IsEmptyStack(s2))
			{
				struct node *temp = pop(s2);
				printf("%d ",temp->data);
				if(temp->right)
				{
					push(s1,temp->right);	
				}
				if(temp->left)
				{
					push(s1,temp->left);	
				}	
			}
			if(IsEmptyStack(s1) && IsEmptyStack(s2))
			{
				break;	
			}					
		}
	}
}
int main()
{
	struct node *root=NULL;
	root = Insert(root,10);
	root = Insert(root,6);
	root = Insert(root,13);
	root = Insert(root,4);
	root = Insert(root,7);
	root = Insert(root,11);
	root = Insert(root,15);
	//create stack
	struct stack *s1 = create(10);
	struct stack *s2 = create(10);
	Zig_Zag(root,s1,s2);
	return 0;
}
