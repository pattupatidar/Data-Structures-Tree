#include<stdio.h>
void rotation(int arr[],int d,int n);
int main()
{
	int n,d,i;
	printf("\n Enter the no of elements in array and no of raotations:");
	scanf("%d%d",&n,&d);
	int arr[n];
	printf("\n Enter the array elements ::\n");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n Array is :\n");
	for(i=1;i<=n;i++)
	{
		printf("%d",arr[i]);
	}
	rotation(arr,d,n);
	return 0;
}
void rotation(int arr[],int d,int n)
{
	int temp,i,j;
	for(i=1;i<=d;i++)
	{
		temp=arr[1];
		for(j=1;j<n;j++)
		{
			arr[j]=arr[j+1];
		}
		if(j==n)
		{
			arr[j]=temp;
		}
	}
	printf("\n new array is ::\n");
	for(i=1;i<=n;i++)
	{
		printf("%d",arr[i]);
	}
	
}
