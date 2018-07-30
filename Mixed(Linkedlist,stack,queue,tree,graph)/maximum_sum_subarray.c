#include<stdio.h>
int main()
{
	int n;
	printf("\n Enter the no of elements : ");
	scanf("%d",&n);
	int i,arr[n];
	int start=0,end=0,s=0;
	printf("\n enter elements:\n ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int max_sum=arr[0];
	int curr = 0;
	printf("\n Entered array is :\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	for(i=0;i<n-1;i++)
	{
		curr+=arr[i];
		if(max_sum<curr)
		{
			max_sum=curr;
			start=s;
			end=i;
		}
		if(curr<0)
		{
			s=i+1;
			curr=0;
		}
	}
	printf("\n maximum sum subarray is : \n");
	for(i=start;i<=end;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
	
}
