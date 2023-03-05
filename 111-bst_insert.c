#include "binary_trees.h"

/**
 * bst_sort_insert - sorts the posttion in which a given node is to fill
 * in a BST
 * @tree: double pointer to the root
 * @value: value to be sorted into the node
 *
 * Return: pointer to the sorted node
 */

bst_t *bst_sort_insert(bst_t **tree, int value)
{
	bst_t *new;

	if (*tree)
	{
		if ((*tree)->n > value)
		{
			if (!(*tree)->left)
			{
				(*tree)->left = binary_tree_node(*tree, value);
				return ((*tree)->left);
			}
			else
			{
				new = bst_sort_insert(&(*tree)->left, value);
				return (new);
			}
		}
		if ((*tree)->n < value)
		{
			if (!(*tree)->right)
			{
				(*tree)->right = binary_tree_node(*tree, value);
				return ((*tree)->right);
			}
			else
			{
				new = bst_sort_insert(&(*tree)->right, value);
				return (new);
			}
		}
	}
	return (NULL);
}
/**
 * bst_insert - inserts a node in a BST
 * @tree: pointer to the root node
 * @value: value to be stored in the root node
 * Return: pointer to the inserted node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	else
		return (bst_sort_insert(tree, value));
	return (NULL);
}
