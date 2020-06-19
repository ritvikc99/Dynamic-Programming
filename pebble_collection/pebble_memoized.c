#include "stdio.h"

const int ROWS = 5;
const int COLUMNS = 6;

int initialize(int map[ROWS][COLUMNS], int memos[ROWS][COLUMNS])
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
			memos[i][j] = -1;
		++i;
	}
	return 0;
}

int recursive(int thisRow, int thisColumn, int map[ROWS][COLUMNS], int memos[ROWS][COLUMNS])
{
	if(thisRow < 0 || thisColumn < 0)
		return 0;
	
	int greatest, a, b;
	
	if(memos[thisRow][thisColumn] != -1)
		return memos[thisRow][thisColumn];	
		
	a = recursive(thisRow - 1, thisColumn, map, memos);
	b = recursive(thisRow, thisColumn - 1, map, memos);
	
	greatest = a;
	if(b > greatest)
		greatest = b;
	
	memos[thisRow][thisColumn] = greatest + map[thisRow][thisColumn];	
	return memos[thisRow][thisColumn];
}

int main()
{
	int map[ROWS][COLUMNS];
	int memos[ROWS][COLUMNS];
	
	initialize(map, memos);
	int pebbles = recursive(ROWS - 1, COLUMNS - 1, map, memos);
	printf("The maximum number of pebbles that can be collected legally is %d.\n", pebbles);
	return 0;
}
