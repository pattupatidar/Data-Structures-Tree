#include<stdio.h>
int max,min;
void max_min(int arr[],int y,int n)
{
	if(y<n)
	{
		if(arr[y]>=max)
		{
			max=arr[y];
		}
		else if(arr[y]<=min)
		{
			min = arr[y];
		}
		y++;
		max_min(arr,y,n);
	}
}
int main()
{
    int i,n;
	printf("\n How many elements are u going to enter ?: ");
    scanf("%d",&n);
    int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	if(arr[0]>arr[1])
    {
  		max=arr[0];
    	min=arr[1];
	}
	else
	{
		max=arr[1];
    	min=arr[0];
	}
	if(n>=2)
	{
		max_min(arr,2,n);
	}
	printf("\n maximum and minimum element of given array is  %d and %d ",max,min);
	return 0;
}
