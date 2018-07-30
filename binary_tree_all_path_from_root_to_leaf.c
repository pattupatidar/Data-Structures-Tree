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
int InOrder(struct node *root,int data)
{
	if(root == NULL)
	{
		return 0;
	}
	//printf("%d ",root->data);
	InOrder(root->left,data);
	if(root->data == data)
	{
		return root;
	}
	InOrder(root->right,data);
	//return root;
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
		return;
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
int Display_Path_sum(struct stack *s,int type)
{
	int i = 0;
	if(type == 1)
	{
		while(i != s->top+1)
		{
			printf("%d ",s->array[i]);
			i++;
		}
		return 0;
	}
	else
	{
		int current_sum = 0;
		while(i != s->top+1)
		{
			current_sum = current_sum + s->array[i];
			i++;
		}
		return current_sum;	
	}
}
void check_path_sum(struct node *root,struct stack *s,int sum)
{
	if(root == NULL)
	{
		return;
	}
	push(s,root->data);
	check_path_sum(root->left,s,sum);
	if(root->left == NULL && root->right == NULL)
	{
		int current_sum = Display_Path_sum(s,0);
		if(sum == current_sum)
		{
			int z = Display_Path_sum(s,1);
		}		
	}
	check_path_sum(root->right,s,sum);
	pop(s);
}
struct node *search(struct node *root,int data)
{
	struct node *temp;
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		if(data == root->data)
		{
			return root;
		}
		else
		{
			temp = search(root->left,data);
			if(temp != NULL)
			{
				return temp;
			}
			else
			{
				return (search(root->right,data));
			}
		}
	}
	return NULL;
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
	//Preorder(root);
	//struct stack *s1 = create(10);
	//printf("\n Path is :");
	//check_path_sum(root,s1,100);
	struct node *ele = search(root,100);
	if(ele == NULL)
	{
		printf("Not found!!!");
	}
	else
	{
		printf("\n Searched element is : %d",ele->data);	
	}
	return 0;
}
