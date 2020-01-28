#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
int partition(T A[], int l, int r)
{
	int m = l;
	int i = l;
	int j = r;

	while (j>i)
	{
		do {
			i++;
		} while (A[i] < A[m]);

		do {
			j--;
		} while (A[j] > A[m]);

		if (j>i)
		{
			/* swap i, j */
			swap(A[i], A[j]);
		}
	}

	swap(A[m], A[j]);
	return j; //return pivot
}

template <class T>
void _quicksort(T A[], int l, int r)
{
	int i = l;
	int j = r;

	if (j>i)
	{
		int pivot = partition(A, l, r);
		_quicksort(A, l, pivot);
		_quicksort(A, pivot + 1, r);
	}
}

//create user friendly interface
template <class T>
void quicksort(T A[], int len)
{
	_quicksort(A, 0, len);
}


int main(int argc, char *argv[]) 
{
	int A[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
	//int A[] = { 435,4325,4,5,65,64,8,32,423,5 };

	quicksort(A, sizeof(A)/sizeof(int));
	for (int i = 0; i < sizeof(A) / sizeof(int); i++) 
	{
		printf("%d ", A[i]);
		assert(A[i] == i);
	}
	printf("\n");
}
