#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int v,e,i,j;
	printf("\n Enter No of vertices and edge in Graph : ");
	scanf("%d%d",v,e);
	int **matrix = malloc(v * sizeof(int *));
	for(i=0;i<v;i++)
	{
		matrix[i] = (int *)malloc(v * sizeof(int));
	}
	/*for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			matrix[i][j] = 0;
		}
	}*/
	return 0;
}


/*
int rows = 2;
    int columns = 5;
    
    int **matrix = (int **) malloc(rows * sizeof(int *));
    
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *) malloc(columns * sizeof(int));
    }
    */
