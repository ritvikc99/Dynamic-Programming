#include "stdio.h"

const int ROWS = 5;
const int COLUMNS = 6;

int initialize(int map[ROWS][COLUMNS])
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
}

int recursive(int thisRow, int thisColumn, int map[ROWS][COLUMNS])
{
	if(thisRow >= ROWS || thisColumn >= COLUMNS)
		return 0;
	
	int greatest, a, b;
	a = recursive(thisRow + 1, thisColumn, map);
	b = recursive(thisRow, thisColumn + 1, map);
	greatest = a;
	if(b > greatest)
		greatest = b;
	return map[thisRow][thisColumn] + greatest;
}

int main()
{
	int map[ROWS][COLUMNS];
	
	initialize(map);
	int pebbles = recursive(0, 0, map);
	printf("The maximum number of pebbles that can be collected legally is %d.\n", pebbles);
	return 0;
}
