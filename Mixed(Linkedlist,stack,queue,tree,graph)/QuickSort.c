
Que. Implementation of Quick Sort Algo.

#include<stdio.h>
int quicksort(int number[],int first,int last) 
{
   	int i, j, pivot, temp;
	if(first<last)
	{
		pivot = number[last];
		j = first;
		i = j-1;
		int k;
		for(k=first;k<=last;k++)
		{
			if(number[k] >= pivot)
			{
				j++;
			}
			else
			{
				int temp;
				i++;
				temp = number[i];
				number[i] = number[j];
				number[j] = temp;
				j++;
			} 
			
		}
		i=i+1;
		temp=number[last];
	    number[last]=number[i];
	    number[i]=temp;
	    quicksort(number,first,i-1);
	    quicksort(number,i+1,last);
	}
}
int main()
{
	int N,i;
	printf("\n Enter No of elements in Array : ");
	scanf("%d",&N);
	int arr[N];  // Array Declaration 
	for(i=0;i<N;i++) // Taking elements from user
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,N); // call function
	printf("\n sorted array is ::\n");
	for(i=1;i<=N;i++) // Displaying Sorted Array 
	{
		printf("%d\t",arr[i]);
	}
	return 0;
}
