#include "stdio.h"

int triangulate(const int MAX, int triangle[MAX][MAX], int * level)
{
	printf("Please enter the number of levels you want the triangle to have: ");
	scanf("%d", &(*level));
	printf("\n");
	
	int n = *level;
	int count = 1;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < count; ++j)
		{
			printf("Now enter element number %d of level %d: ", j + 1, i + 1);
			scanf("%d", &(triangle[i][j]));	
		}
		++count;	
	}
	return 0;	
}

int calculate(const int MAX, int triangle[MAX][MAX], int * level)
{
	int n = (*level - 1); 
	int i = n;
	int smallest = 999999;
	int indexFound = 0;
	for(int j = 0; j <= i; ++j)
	{
		if(triangle[i][j] < smallest)
		{
			smallest = triangle[i][j];
			indexFound = j;
		}
	}

	int count = n - 1;
	int sum = smallest;	
	for(i = count; i >= 0; --i)
	{
		smallest = triangle[i][0];
		for(int j = 0; j <= count; ++j)
		{
			if(triangle[i][j] < smallest)
			{
				if(j == indexFound + 1 || j == indexFound - 1)
				{
					smallest = triangle[i][j];
					indexFound = j;
				}
			}
		}
		sum += smallest;
		--count;
	}
	return sum;
}

int main()
{
	const int MAX = 50;
	int n = 0;
	int * level = &n;
	int triangle[MAX][MAX];
	
	for(int i = 0; i < MAX; ++i)
	{
		for(int j = 0; j < MAX; ++j)
			triangle[i][j] = 999999;
	}

	triangulate(MAX, triangle, level);
	int answer = calculate(MAX, triangle, level);
	printf("\nThe minimum sum in a descending path of adjacent elements from the apex is %d.\n", answer);
	return 0;
}
