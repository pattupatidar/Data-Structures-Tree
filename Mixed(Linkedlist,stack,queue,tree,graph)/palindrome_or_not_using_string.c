#include<stdio.h>
#include<conio.h>
int top = -1;
char stc[10];
void push(char c)
{
	top = top+1;
	stc[top] = c;
}
void pop()
{
	top--;
}
int main()
{
	int n,i;
	char c[10];
	printf("\n Enter the length of the string: ");
	scanf("%d",&n);
	printf("\n Enter string: ");
	for(i=0;i<n;i++)
	{
		scanf("%s",&c[i]);
	}
	for(i=0;i<n;i++)
	{
		if(c[i] == 97 || c[i] == 98)
		{
			push(c[i]);
		}
		else
		{
			break;
		}
	}
	for(i=i+1;i<n;i++)
	{
		if(stc[top] == c[i])
		{
			pop();
		}
		else
		{
			printf("\n Entered String is not pallindrome: ");
			exit(0);
		}
	}
	if(top == -1)
	{
		printf("\n Entered String is pallindrome: ");
	}
	else
	{
		printf("\n Entered String is not pallindrome: ");		
	}
	return 0;
}
