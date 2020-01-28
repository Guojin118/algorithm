#include <iostream>
#include <assert.h>
using namespace std;

/*
 * C++ array index start from zero, so: 
 * left_child(i) = 2*(i+1)-1
 * right_child(i) = 2*(i+1)
 * parent(i) = (i+1)/2 - 1
 */
template <typename T>
void adjust(T A[], int cur, int len)
{
	while (cur < len)
	{
		int left_child = 2 * (cur+1) -1;
		int right_child = 2 * (cur + 1);
		int gck = cur;
		if (left_child<len)  //has left child
		{
			if (right_child < len)
			{ //has right child
				if (A[left_child] > A[right_child])
				{ //left child is greater than right
					if (A[left_child] > A[cur])
					{ //left child is greater than current
						swap(A[left_child], A[cur]);
						gck = left_child;
					}
				}
				else
				{ //right child is greater than left child
					if (A[right_child] > A[cur])
					{ // right child is greater thank current
						swap(A[right_child], A[cur]);
						gck = right_child;
					}
				}
			}
			else
			{  // has only left child
				if (A[left_child] > A[cur])
				{ //left child is greater than current
					swap(A[left_child], A[cur]);
					gck = left_child;
				}
			}
		}

		if (gck == cur)
		{
			break;
		}
		else
		{
			cur = gck;
		}
	}
}

template <typename T>
void heapify_max(T A[], int len) 
{
	for (int i = (len / 2) + 1; i >= 0; i--) 
	{
		int cur = i;
		adjust(A, cur, len);
	}
}

template <typename T>
void remove_head(T A[], int len)
{	//A is heapfied array
	int cur = 0;
	swap(A[0], A[len - 1]);
	adjust(A, 0, len-1);
	
}

template <typename T>
void _heapfied_sort(T A[], int len)
{
	for (int i = 0; i < len; i++)
	{
		remove_head(A, len - i);
	}
}

template <typename T>
void heapsort(T A[], int len) 
{
	heapify_max(A, len);
	_heapfied_sort(A, len);
}

int main(int argc, char *argv[]) 
{
	int A[] = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
	//int A[] = { 435,4325,4,5,65,64,8,32,423,5 };

	heapsort(A, sizeof(A)/sizeof(int));
	for (int i = 0; i < sizeof(A) / sizeof(int); i++) 
	{
		printf("%d ", A[i]);
		assert(A[i] == i);
	}
	printf("\n");
}
