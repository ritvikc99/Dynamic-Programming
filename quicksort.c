//Ritvik Chitram, CS350, Winter 2020
//Program 3(b), Partition Sort

#include <stdio.h>

int getArray(int array[], int upperBound) //gets user input of unsorted integers
{
	int i;
	for(i = 0; i <= upperBound; ++i)
	{
		printf("Now enter integer number %d: ", i + 1);
		scanf("%d", &(array[i])); //saves unsorted integers to an array
		while((getchar()) != '\n'); //flushes input buffer
	}	
	printf("\n");
	return 0;
}

//function to correctly place the lowest index element(lowerBound) and return new location
int place(int array[], int lowerBound, int upperBound)
{
	int current = array[lowerBound]; //the number we want to place, saves us from pointer arithmetic every time
	int p1 = lowerBound + 1; //lower pointer
	int p2 = upperBound; //upper pointer
	int temp; //temporary for swapping	
	do
	{
		while(p1 < p2 && array[p1] <= current) //finds elements larger than current, starting from left
			++p1;
		while(array[p2] > current) //finds elements smaller than current, starting from right
			--p2;
		if(p2 == p1) //we know that p1 >= p2 this conditional addresses the equality case
		{
			if(array[p1] < current) //if pointers coincide with an element smaller than current, that is the correct position for current
			{
				temp = array[p1];
				array[p1] = array[lowerBound];
				array[lowerBound] = temp;
			}
			return p1; //returns new current location
		}
		if(p1 < p2) //common case of lower pointer being less than upper pointer
		{
			temp = array[p1];
			array[p1] = array[p2];
			array[p2] = temp;
		}
	}while(p2 >= p1); //loops while upper pointer is greater than or equal to lower pointer (case of equality is addressed within the loop)
	if(p2 < p1) //overlap case when upper pointer becomes smaller than the lower pointer
	{
		temp = array[p2]; //swaps current with upper pointer's location
		array[p2] = current;
		array[lowerBound] = temp;
		return p2; //returns upper pointer (current's correct location)
	}
}

//recursive function to split array into 2 subarrays, excluding the correctly placed integer
int sort(int array[], int lowerBound, int upperBound, int SIZE)
{
	if(lowerBound < 0 || upperBound > SIZE) //if we reach the base case, return 0
		return 0;
	if(lowerBound < upperBound) //while we are allowed to split, place the leftmost element correctly, and return its new position
	{
		int placed = place(array, lowerBound, upperBound); 
	
		sort(array, lowerBound, placed - 1, SIZE); //recursive call with smaller subarray
		sort(array, placed + 1, upperBound, SIZE); //recursive call with larger subarray
	}
	return 0;
}

int main()
{
	const int MAX = 1000; //constant for the max size of our static arrays
	int array[MAX]; //array to hold the integers
	int lowerBound = 0; //we always start sorting from 0 to upperBound
	int upperBound;
	
	printf("First enter the number of integers you wish to sort: ");
	scanf("%d", &upperBound);
	while((getchar()) != '\n');
	printf("\n");
	upperBound = upperBound - 1; //since the highest index of an n-item array is "n-1"
	getArray(array, upperBound);
	sort(array, lowerBound, upperBound, upperBound);
	printf("\nThe sorted list is:\n");
	for(int c = 0; c <= upperBound; ++c)
	{
		printf("%d, ", array[c]);
	}
	printf("\n");

	return 0;
}
