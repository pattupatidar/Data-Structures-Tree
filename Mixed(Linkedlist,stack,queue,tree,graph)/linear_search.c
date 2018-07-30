#include<stdio.h>
void linear_search(int arr[],int n)
{
	int i,item;
	printf("\n enter the element that you want to search : ");
	scanf("%d",&item);
	for(i=0;i<n;i++)
	{
		if(arr[i]==item)
		{
			printf("\n item found at location %d ",i);
			break;
		}
	}
	if(i==n)
	{
		printf("\n Item not found");
	}
	
}
int main()
{
	int n,i,j;
	printf("\n Enter the no of elements :");
	scanf("%d",&n);
	int arr[n];
	printf("\n Enter array elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	linear_search(arr,n);
	return 0;
}

