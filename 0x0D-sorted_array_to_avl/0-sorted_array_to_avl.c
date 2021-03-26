#include "binary_trees.h"

/**
* sorted_array_to_avl - Function that builds an AVL tree from an array
* @array: is a pointer to the first element of the array to be converted
* @size: is the number of element in the array
* Return: a pointer to the root node of the created AVL tree, otherwise NULL
*/

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;

	if (!array || !size)
		return (NULL);

	root = insert_node(array, 0, size - 1, NULL);
	return (root);
}


/**
* insert_node - Function that build an AVL tree from an array
* @array: is a pointer to the first element of the array to be converted
* @start: the first element array index
* @end: the last element array to eval
* @parent: is a ponter to the parent of the new node
* Return: binary tree, otherwise NULL
*/
avl_t *insert_node(int *array, size_t start, size_t end, avl_t *parent)
{
	size_t middle;
	avl_t *root;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	root = new_node(parent, array[middle]);
	if (!root)
		return (NULL);

	if (middle != start)
		root->left = insert_node(array, start, middle - 1, root);

	if (middle != end)
		root->right = insert_node(array, middle + 1, end, root);

	return (root);
}

/**
* new_node - Function to create a new node
* @parent: is a ponter to the array
* @n: size of the array
* Return: the pointer of the node, otherwise NULL
*/
avl_t *new_node(avl_t *parent, size_t n)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));

	if (!new)
		return (NULL);

	new->n = n;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;

	return (new);
}