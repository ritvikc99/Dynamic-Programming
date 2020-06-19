#include "stdio.h"

const int ROWS = 5;
const int COLUMNS = 6;

int initialize(int map[ROWS][COLUMNS], int table[ROWS][COLUMNS])
{
	int i = 0;
	while(i < ROWS)
	{
		for(int j = 0; j < COLUMNS; ++j)
			map[i][j] = 0;
		++i;
	}
	
	map[0][4] = 1;
	map[1][1] = 1;
	map[1][3] = 1;
	map[2][3] = 1;
	map[2][5] = 1;
	map[3][2] = 1;
	map[3][5] = 1;
	map[4][0] = 1;
	map[4][4] = 1;

	i = 0;
	while(i < ROWS)
	{
		for(int j = 0; j < COLUMNS; ++j)
			table[ROWS][COLUMNS] = -1;
		++i;
	}
	return 0;
}

int tabular(int map[ROWS][COLUMNS], int table[ROWS][COLUMNS])
{
	for(int i = 1; i < ROWS; ++i)
	{
		for(int j = 1; j < COLUMNS; ++j)
		{
			int a = map[i-1][j];
			int b = map[i][j - 1];
			if(a > b)
				table[i][j] = a;
			else
				table[i][j] = b;
			
		}
	}
	return 0;
}

int main()
{
	int map[ROWS][COLUMNS];
	int table[ROWS][COLUMNS];
	
	initialize(map, table);
	int pebbles = tabular(map, table);
	printf("The maximum number of pebbles that can be collected legally is %d.\n", pebbles);
	return 0;
}
