#include "stdio.h"

int tabulate(int table[], const int MAX)
{
	for(int i = 1; i < MAX; ++i)
	{
		if(i == 1 || i == 3 || i == 5)
			table[i] = 1;
		else if(i == 2 || i == 4)
			table[i] = 2;

		else
		{	
			int a, b, c, least;
			a = table[i - 1];
			b = table[i - 3];
			c = table[i - 5];
			least = a;
			if(b < least)
				least = b;
			if(c < least)
				least = c;		
			table[i] = least + 1;
		}
	}
	return 0;
}

int main()
{
	const int MAX = 1000;
	int table[MAX];
	table[0] = 0;	
	tabulate(table, MAX);

	int toReduce = 0;
	printf("This program has already tabulated the least exact change in denominations of 1, 3, and 5 cent coins for upto %d cents.\n", MAX);
	printf("Please enter the number of cents you want change for: ", MAX);
	scanf("%d", &toReduce);
	printf("\nThe least number of coins as change for %d cents is %d.\n", toReduce, table[toReduce]);
	return 0;
}
