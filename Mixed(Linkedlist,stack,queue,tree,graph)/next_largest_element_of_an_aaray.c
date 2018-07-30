#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],stack[n];
	int i;
	printf("\n Enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int top=-1;
	i=0;
	while(i<n)
	{
		if(top==-1)
		{
			top++;
			stack[top]=arr[i];
			i++;
		}
		else
		{
			if(stack[top]<=arr[i])
			{
				printf("\n next largest element of the %d is %d:",stack[top],arr[i]);
				top--;
			}
			else
			{
				top++;
				stack[top] = arr[i];
				i++;
			}
		}
	}-
	return 0;
}
