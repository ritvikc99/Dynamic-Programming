#include "stdio.h"

int tabulate(int table[], const int MAX)
{
	for(int i = 1; i < MAX; ++i)
	{
		if(i == 1 || i == 3 || i == 4)
			table[i] = 1;
		if(i == 2 || i == 5)
			table[i] = 2;
	
		int a, b, c, least;
		a = table[i - 4];
		b = table[i - 3];
		c = table[i - 5];
		least = a;
		if(b < least)
			least = b;
		if(c < least)
			least = c;
		
		table[i] = least + 1;
	}
	return 0;
}

int main()
{
	const int MAX = 500;
	int table[500];
	
	tabulate(table, MAX);

	int toReduce = 0;
	printf("This program has already tabulated the least number of coins in change for upto 500 cents. Please enter the number of cents you want change for: ");
	scanf("%d", &toReduce);
	printf("\nThe least number of coins as change for %d cents is %d.\n", toReduce, table[toReduce]);

	return 0;
}
