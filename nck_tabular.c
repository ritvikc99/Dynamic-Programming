#include "stdio.h"

int tabulate(const int MAX, int table[])
{
	table[0] = 1;

	for(int i = 1; i < MAX; ++i)
		table[i] = i * table [i - 1];
	
	return 0;	
}

int main()
{
	const int MAX = 500;
	int table[MAX];
	int n, k;

	tabulate(MAX, table);
	printf("This program has already tabulated 'n' choose 'k' for n values up till %d.\n", MAX);
	printf("Please enter your 'n' value: ");
	scanf("%d", &n);
	printf("Please enter your 'k' value: ");
	scanf("%d", &k);
	
	int answer = table[n]/(table[n - k] * table[k]);
	printf("\n%d choose %d is %d.\n", n, k, answer);

	return 0;
}
