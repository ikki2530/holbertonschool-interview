#include "binary_trees.h"

/*heap_t *LevelOrder(heap_t *root, int value)
{
	heap_t *new;
	if (root == NULL)
	{
		new = binary_tree_node(root, value);
		return (new);
	}

	if ()
}*/

/*count the number of nodes*/

unsigned int binarytree_count_recursive(heap_t **root)
{
    unsigned int count = 1;
    if ((*root)->left != NULL) {
       count += binarytree_count_recursive(&(*root)->left);
    }
    if ((*root)->right != NULL) {
        count += binarytree_count_recursive(&(*root)->right);
    }
    return count;
}
 
unsigned int binarytree_count(heap_t **tree)
{
    unsigned int count = 0;
    if ((*tree) != NULL) {
        count = binarytree_count_recursive(&(*tree));
    }
    return count;
}
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to put in the new node
 * Return: a pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new = *root;
	unsigned int count;

	if ((*root) == NULL)
	{
		printf("hola\n");
		new = binary_tree_node(*root, value);
		return (new);
	}

	count = binarytree_count(&(*root));
	printf("number of nodes %ui, value %d\n", count, value);
	return (new);

}
