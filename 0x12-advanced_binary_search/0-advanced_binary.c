#include "search_algos.h"

/**
* search - search function
* @array: array
* @min: min value array
* @max: max value array
* @value: value to look for
* Return: the index of the value searched
*/
int search(int *array, int min, int max, int value)
{
	int mid = (min + max)  / 2, i;

	if (min > max)
		return (-1);
	printf("Searching in array: ");
	for (i = min; i <= max; i++)
	{
		if (i == max)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}
	if (array[mid] == value)
	{
		if (array[mid - 1] == value)
			return (search(array, min, mid, value));
		return (mid);
	}
	else if (array[mid] >= value)
		return (search(array, min, mid, value));
	else
		return (search(array, mid + 1, max, value));
	return (-1);
}
/**
* advanced_binary - binary search
* @array: pointer of array to search in
* @size: numbers of elements in array
* @value: value to search for
* Return: the index of the value searched
*/
int advanced_binary(int *array, size_t size, int value)
{
	int min = 0, max = (int)size - 1;

	if (array == NULL || size <= 0)
		return (-1);
	return (search(array, min, max, value));
}
