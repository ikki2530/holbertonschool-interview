
#include "sort.h"

/**
* siftDown - Repair the heap whose root element
* is at index 'start', assuming the heaps
* rooted at its children are valid
* @array: sorting array
* @start: start array
* @end: end of array
* @size: length array
*/
void siftDown(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start, swap, child;
	int aux;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;
		if (array[swap] <  array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			aux = array[root];
			array[root] = array[swap];
			array[swap] = aux;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
* heapify - function that Build the heap
* in array a so that largest value is at the root
* @array: sorting array
* @size: length array
*/
void heapify(int *array, size_t size)
{
	int start = (size - 1) / 2;

	while (start >= 0)
	{
		siftDown(array, start, size - 1, size);
		start = start - 1;
	}
}

/**
* heap_sort - function that sorts an array
* of integers in ascending order using the Heap sort algorithm
* @array: sorting array
* @size: length array
*/
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;
	int aux;

	if (size < 2)
		return;
	heapify(array, size);
	while (end > 0)
	{
		aux = array[end];
		array[end] = array[0];
		array[0] = aux;
		print_array(array, size);
		end = end - 1;
		siftDown(array, 0, end, size);
	}
}