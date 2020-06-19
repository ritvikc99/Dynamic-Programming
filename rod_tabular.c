#include "stdio.h"

int tabulate(int n, int p[], int table[])
{
	table[1] = p[1];	
	int greatest = 0;
	for(int i = 2; i <= n; ++i)
	{
		for(int j = 1; j <= i; ++j)
		{
			if((p[j] + table[i - j]) > greatest)
				greatest = p[j] + table[i - j];
		}
		table[i] = greatest;
	}
	return table[n];
}

void initialize(const int MAX, int * length, int p[], int table[])
{
	printf("Please enter the length of the whole rod: ");
	scanf("%d", &(*length));
	p[0] = 0;
	for(int i = 1; i <= *length; ++i)
	{
		printf("Now enter the price for a piece of length %d unit(s): ", i);
		scanf("%d", &p[i]);
	}
	for(int i = 0; i < MAX; ++i)
		table[i] = 0;
}

int main()
{
	const int MAX = 500; //maximum size for tabulation
	int n; //length of the rod
	int * length = &n; //only used for the initialize function
	int table[MAX]; //table of maximum total sale prices
	int p[MAX]; //array of prices of various lengths	
	initialize(MAX, length, p, table);
	int index = tabulate(n, p, table);
	printf("\nThe maximum total sale price by cutting a rod of length %d into pieces is $%d.\n", n, index);
	return 0;
}
