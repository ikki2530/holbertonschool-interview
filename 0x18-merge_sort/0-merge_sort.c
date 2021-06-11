#include "sort.h"
/**
 * merge - merges l and r arrays into original array
 * @array: pointer to array
 * @size: size of the array
 * @L: pointer to left array
 * @R: pointer to right array
 **/
void merge(int *array, int *L, int *R, size_t size)
{
	int i = 0, j = 0, k = 0;
	int size_l, size_r;

	size_l = size / 2;
	size_r = size - size_l;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(L, size_l);
	printf("[right]: ");
	print_array(R, size_r);
	while (i < size_l && j < size_r)
	{
		if (L[i] < R[j])
			array[k++] = L[i++];
		else
			array[k++] = R[j++];
	}
	while (i < size_l)
		array[k++] = L[i++];
	while (j < size_r)
		array[k++] = R[j++];
	printf("[Done]: ");
	print_array(array, size);
}
/**
 * merge_sort - sorts an array of integers using
 * the Merge sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void merge_sort(int *array, size_t size)
{
	size_t middle = 0, i;
	int L[100];
	int R[100];

	if (array == NULL || size < 2)
		return;
	middle = size / 2;
	for (i = 0; i < middle; i++)
		L[i] = array[i];
	for (i = middle; i < size; i++)
		R[i - middle] = array[i];
	merge_sort(L, middle);
	merge_sort(R, size - middle);
	merge(array, L, R, size);
}
