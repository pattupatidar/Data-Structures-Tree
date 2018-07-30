#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node 
{
	int data;
	struct node *left;
	struct node *right;
};
struct ListNode
{
	int data;
	struct ListNode *pre;
	struct ListNode *next;
};
struct node * getNewNode(int data)
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	new->data = data;
	new->left = new->right = NULL;
	return new;
}
struct node * insert(struct node *root,int data)
{
	if(root == NULL)
	{
		root = getNewNode(data);
	}
	else
	{
		if(data < root->data)
		{
			root->left = insert(root->left,data);
		}
		else
		{
			root->right = insert(root->right,data);
		}
	}
	return root;
}
void inorder(struct node *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
struct ListNode * convert(struct node *root,struct ListNode *head)
{
	static struct ListNode *previous = NULL;
	static int count = 0;
	if(root == NULL)
	{
		return;
	}
	convert(root->left,head);
	struct ListNode *temp = (struct ListNode *)malloc(sizeof(struct ListNode));
	temp->data = root->data;
	printf("\n Data of temp is %d and root data is %d",temp->data,root->data);
	temp->next = NULL;
	if(head == NULL)
	{
		//printf("\n Prateek");
		temp->pre = previous;
		previous = temp;
		head = temp;	
	} 
	else
	{
		previous->next = temp;
		temp->pre = previous;
		previous = temp;
	}
	printf("\n ->->->->->->->->->data of head is %d",head->data);
	convert(root->right,head);
	return head;
}
void displayList(struct ListNode *head)
{
	printf("data of head is %d",head->data);
	struct ListNode *ptr = head;
	printf("\n");
	while(ptr != NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
}
int main()
{
	struct node *root = NULL;
	struct ListNode *head = NULL;
	root = insert(root,10);
	root = insert(root,5);
	root = insert(root,15);
	root = insert(root,2);
	root = insert(root,7);
	root = insert(root,12);
	root = insert(root,20);
	root = insert(root,1);
	root = insert(root,6);
	inorder(root);
	head = convert(root,head);
	displayList(head);
	return 0;
}
