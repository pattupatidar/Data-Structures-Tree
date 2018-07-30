#include<stdio.h>
#include<conio.h>
char stc[12];
int top=-1;
char pop()
{
	char c = stc[top];
	top--;
	return c;
}
void push(char c)
{
	top = top+1;
	stc[top] = c;
}
int priority(char c)
{
	if((c == '-') || (c == '+'))
	{
		return 1;
	}
	else if((c == '*') || (c == '/') || (c == '%'))
	{
		return 2;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char exp[12];
	char output[12];
	int n,i,j=0;
	printf("\n Enter the length of the input expression: ");
	scanf("%d",&n);
	printf("\n Enter input expression that needs to be converted into the postfix : ");
	for(i=0;i<n;i++)
	{
		scanf("%s",&exp[i]);
	}
	printf("\n Entered infix expression is: ");
	for(i=0;i<n;i++)
	{
		printf("%c ",exp[i]);
	}
	for(i=0;i<n;i++)
	{
		if((65 <= exp[i] && exp[i] <= 90) || (97 <= exp[i] && exp[i] <= 122) )
		{
			output[j] = exp[i];
			j++;
		}
		else if(exp[i] == 40)
		{
			push(exp[i]);
		}
		else if(exp[i] == 41)
		{
			
			while(stc[top] != 40)
			{
				output[j] = pop();
				j++;
			}
			pop();
		}
		else
		{
			if(top ==-1)
			{
				push(exp[i]);
			}
			else if(priority(exp[i]) <= priority(stc[top]))
			{
				output[j] = pop();
				j++;
				push(exp[i]);
			}
			else
			{
				push(exp[i]);
			}
		}
		if(i == n-1)
		{
			while(top != -1)
			{
				output[j] = pop();
				j++;
			}
		}
	}
	printf("\n Postfix Expression is:  ");
	for(i=0;i<n;i++)
	{
		printf("%c",output[i]);
	}
	return 0;
}
