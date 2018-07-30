#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node * GetNewNode(int data)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
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
void Inoreder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	else
	{
		Inoreder(root->left);
		printf("%d ",root->data);
		Inoreder(root->right);
	}
}
struct node * findMin(struct node *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		if(root->left == NULL)
		{
			return root;
		}
		else
		{
			return findMin(root->left);
		}
	}
}
struct node * findMax(struct node *root)
{
	if(root == NULL)
	{
		return NULL;
	}
	else
	{
		if(root->right == NULL)
		{
			return root;
		}
		else
		{
			return findMax(root->right);
		}
	}
}
struct node *search(struct node *root,int data)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(root->data > data)
	{
		return search(root->left,data);
	}
	else
	{
		return search(root->right,data);
	}
	return root;
}
struct node * findInorderPredecessor(struct node *root)
{
	return findMax(root->left);
}
struct node * findInorderSuccessor(struct node *root)
{
	return findMin(root->right);
}
int main()
{
	struct node *root = NULL,*temp = NULL;
	root = Insert(root,4);
	root = Insert(root,2);
	root = Insert(root,8);
	root = Insert(root,1);
	root = Insert(root,5);
	root = Insert(root,9);
	root = Insert(root,7);
	root = Insert(root,6);
	Inoreder(root);
	//temp = Deletion(root,8);
	//printf("\n After Deleting Element: \n");
	//Inoreder(root);
	struct node *find_min = findMin(root);
	printf("\n Minimum Element of the tree is %d",find_min->data);
	printf("\n Maximum Element of the tree is %d",findMax(root)->data);
	/*printf("\n Searched Element ");
	struct node *sea = search(root,8);
	if(sea == NULL)
	{
		printf("Not Present");
	}
	else
	{
		printf("Present");
	}*/
	printf("\n Inorder Predecessor :");
	struct node *ele1,*ele2;
	ele1 = findInorderPredecessor(root);
	ele2 = findInorderSuccessor(root);
	printf("%d   %d",ele1->data,ele2->data);
	return 0;
}
