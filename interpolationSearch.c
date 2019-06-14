#include <stdio.h>
#include <math.h>


// find out if a target x exists in the sorted array A
// or not using Interpolation search algorithm
int InterpolationSearch(int A[], int n, int x)
{
	// search space is A[low..high]
	int low = 0, high = n - 1, mid;

	while (A[high] != A[low] && x >= A[low] && x <= A[high])
	{
		// estimate mid
		mid = low + ((x - A[low]) * (high - low) / (A[high] - A[low]));
		mid = roundf(mid);
		printf("%d",mid);
		printf("\n");

		// target value is found
		if (x == A[mid])
			return mid;

		// discard all elements in the right search space
		// including the mid element
		else if (x < A[mid])
			high = mid - 1;

		// discard all elements in the left search space
		// including the mid element
		else
			low = mid + 1;
	}

	// if target is found
	if (x == A[low])
		return low ;

	// x doesn't exist in the array
	else
		return -1;
}

// Interpolation search algorithm
int main(void)
{
	int A[] = {0011,0022,0033,	1144,	1166,	1188,	3322,	3344,	3399};
	int target = 1166;

	int n = sizeof(A)/sizeof(A[0]);
	int index = InterpolationSearch(A, n, target);

	if (index != -1)
		printf("Element found at index %d", index);
	else
		printf("Element not found in the array");

	return 0;
}
