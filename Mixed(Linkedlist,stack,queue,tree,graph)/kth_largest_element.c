#include<stdio.h>
void largest(int n,int arr[],int k)
{
	int x=0,i=0,j;
	while(x<k)
	{
		int pos;
		pos=i;
		for(j=i;j<n;j++)
		{
			if(arr[pos]<=arr[j])
			{
				pos=j;
			}
		}
		if(pos!=i)
		{
			int temp;
			temp=arr[pos];
			arr[pos]=arr[i];
			arr[i]=temp;
		}
		if(i==0)
		{
			x++;
		}
		if(arr[i-1]==arr[i])
		{
			x;
		}
		else
		{
			x++;
		}
		i++;
	}	
	printf("\n kth largest element of array is : %d",arr[i]);
}
int main()
{
	int n,i,j,k;
	printf("\n Enter the no of elements :");
	scanf("%d",&n);
	int arr[n];
	printf("\n Enter array elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n Enter the value for k which is the kth largest element of array : ");
	scanf("%d",&k);
	largest(n,arr,k);
	return 0;
}
