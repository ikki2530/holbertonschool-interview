#include "binary_trees.h"

#include "binary_trees.h"


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: heihgt of the binary tree
 */
int binary_tree_height(heap_t *tree)
{
	int right1 = 0, left1 = 0;


	if (tree == NULL)
		return (0);

	if (tree->left)
		left1 = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right1 = 1 + binary_tree_height(tree->right);

	if (left1 > right1)
		return (left1);
	else
		return (right1);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: balance factor
 */
int binary_tree_balance(heap_t *tree)
{
	int hleft = 0, hright = 0, balance_fact = 0;

	if (tree == NULL)
		return (0);

	hleft += binary_tree_height(tree->left);
	hright += binary_tree_height(tree->right);
	balance_fact = hleft - hright;

	return (balance_fact);

}
/**
 * print_level - recursive function to print each level
 * @tree: pointer to the root node of the tree to traverse
 * @level: current level to print
 * Return: Nothing
 */
heap_t *print_level(heap_t *tree, int level)
{
	heap_t *flag = NULL;
	if (tree == NULL)
	{
		return (NULL);
	}
		
	if (level >= 0)
	{
		if ((tree)->left == NULL)
		{
			return (tree);
		}
		else if ((tree)->right == NULL)
		{
			return (tree);
		}
		else 
		{
			if (tree->left != NULL)
				flag = print_level(tree->left, level - 1);
			if (flag != NULL)
			{
				return (flag);
			}
			if (tree->right != NULL)
				flag = print_level(tree->right, level - 1);
			if (flag != NULL)
				return (flag);
		}
	}
	return (NULL);
}
/**
 * print_tree_level - goes through levels in the binary tree
 * @tree: pointer to the root node of the tree to traverse
 * Return: NOthing
 */
heap_t *print_tree_level(heap_t *tree)
{
	int height = 0, balance=0;

	heap_t *flag = NULL;

	height = binary_tree_height(tree);
	balance = binary_tree_balance(tree);
	if (balance > 0)
		flag = print_level(tree, height - (height - 1));
	else if (balance == 0)
		flag = print_level(tree, height);
	else
	{
		flag = print_level(tree, height);
	}
	return (flag);
}
/**
 * binary_tree_levelorder - goes through a btree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * Return; Nothing
 */
heap_t *binary_tree_levelorder(heap_t *tree)
{
	heap_t *flag = NULL;
	if (tree == NULL)
		return (NULL);
	flag = print_tree_level(tree);

	return (flag);
}
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to put in the new node
 * Return: a pointer to the inserted node, or NULL on failure
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *parent;

	new = binary_tree_node(*root, value);
	if ((*root) == NULL)
	{
		*root = new;
		return (new);
	} 
	else if ((*root)->left == NULL)
	{
		(*root)->left = new;
		new->parent = (*root);
		return (new);
	}
	else if ((*root)->right == NULL)
	{
		(*root)->right = new;
		new->parent = (*root);
		return (new);
	}
	parent = binary_tree_levelorder(*root);
	if (parent == NULL)
		return (NULL);
	if (parent->left == NULL)
	{
		parent->left = new;
		new-> parent = parent;
		return (parent->left);
	} else if (parent->right == NULL)
	{
		parent->right = new;
		new-> parent = parent;
		return (parent->right);
	}
	return (new);
}
