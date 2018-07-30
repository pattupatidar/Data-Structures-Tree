#include<stdio.h>
void count_frequency(int arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		count=0;
		for(j=0;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
			}
		}
		printf("\n ")	
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
	count_frequency(arr,n);
	return 0;
}

