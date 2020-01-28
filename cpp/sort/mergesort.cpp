#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
void merge(T A[], int s, int m, int e) {
	T* B = new T[e - s + 1];
	int i = s; 
	int j = m+1;
	int k = 0;
	while (i <= m && j <= e) {
		if (A[i] < A[j]) {
			B[k++] = A[i++];
		}
		else
		{
			B[k++] = A[j++];
		}
	}

	for ( ;i<=m; i++)
	{ 
		B[k++] = A[i];
	}

	for (;j <= e; j++)
	{
		B[k++] = A[j];
	}
	

	k = 0;
	for (int i = s; i <= e; i++) {
		A[i] = B[k++];
	}

	delete[] B;
}

template <typename T>
void _mergesort(T A[], int l, int r)
{
	if (r > l)
	{
		int m = (l + r) / 2;

		_mergesort(A, l, m);
		_mergesort(A, m + 1, r);
		merge(A, l, m, r);
	}
}

template <typename T>
void mergesort(T A[], int len)
{
    _mergesort(A, 0, len-1);
}

int main(int argc, char *argv[]) 
{
	int A[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
	//int A[] = { 435,4325,4,5,65,64,8,32,423,5 };

	mergesort(A, sizeof(A)/sizeof(int));
	for (int i = 0; i < sizeof(A) / sizeof(int); i++) 
	{
		printf("%d ", A[i]);
		assert(A[i] == i);
	}
	printf("\n");
}

