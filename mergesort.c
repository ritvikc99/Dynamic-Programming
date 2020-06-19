//Ritvik Chitram, CS350, Winter 2020
//Program 3(a), Merge Sort

#include <stdio.h>

const int MAX = 1000; //global constant for the max size of our static arrays (will place in main after testing)

int getArray(int unsorted[], int upperBound) //gets user input of unsorted integers
{
	int i;
	for(i = 0; i <= upperBound; ++i)
	{
		printf("Now enter integer number %d: ", i + 1);
		scanf("%d", &unsorted[i]); //saves unsorted integers to an array
		while((getchar()) != '\n');
	}	
	printf("\n");
	return 0;
}

//this function evaluates the elements of the left and right sub arrays and saves whichever element is smaller to sorted array
int merge(int unsorted[], int sorted[], int lower, int mid, int upper)
{
	int left = lower; //starting index of left sub array
	int right = mid + 1; //starting index of right sub array
	for(int i = lower; i <= upper; ++i)
	{
		if(left == mid + 1) //case when left sub array is finished (and right remains)
		{
			sorted[i] = unsorted[right];
			++right;
		}
		else if(right == upper + 1) //case when right sub array is finished (and left remains)
		{
			sorted[i] = unsorted[left];
			++left;
		}
		else if(unsorted[left] < unsorted[right]) //case when left element is smaller
		{
			sorted[i] = unsorted[left];
			++left;
		}
		else //case when right element is smaller
		{
			sorted[i] = unsorted[right];
			++right;
		}
	}
	return 1;
}

//this function does the recursive array splitting
int split(int unsorted[], int sorted[], int lowerBound, int upperBound)
{
	//printf("%d and %d\n", lowerBound, upperBound);
	if(lowerBound >= upperBound)
	{
		//printf("\nBase case triggered.");
		//getchar();
		return 0;
	}
	int middle = (lowerBound + upperBound)/2; //finds the middle element (automatically truncates when there is a remainder)
	split(unsorted, sorted, lowerBound, middle); //recursive call with lower half
	split(unsorted, sorted, middle + 1, upperBound); //recursive call with upper half
	merge(unsorted, sorted, lowerBound, middle, upperBound); //calls the function that actually does the sorting

	//replaces unsorted array elements with [auxiliary] sorted array elements in each recursive call
	//first call (final stack frame) copies the entire array
	int count;
	for(count = lowerBound; count <= upperBound; ++count)
	{
		unsorted[count] = sorted[count];
	}
	return 1;
}

int main()
{
	int unsorted[MAX];
	int sorted[MAX];
	int lowerBound = 0;
	int upperBound;
	
	printf("First enter the number of integers you wish to sort: ");
	scanf("%d", &upperBound);
	while((getchar()) != '\n');
	printf("\n");
	upperBound = upperBound - 1; //since the highest index of an n-item array is "n-1"
	getArray(unsorted, upperBound);
	split(unsorted, sorted, lowerBound, upperBound); //first call with whole array as bounds
	printf("\nThe sorted list is:\n");
	for(int c = 0; c <= upperBound; ++c)
	{
		printf("%d, ", unsorted[c]);
	}
	printf("\n");

	return 0;
}
