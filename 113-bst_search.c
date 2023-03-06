#include "binary_trees.h"

/**
 * search - searches a BST for a given value
 * @tree: pointer to the root node
 * value: value we seek in the tree
 *
 * Return: pointer to the node if found
 */

bst_t *search_value(const bst_t *tree, int value)
{
	const bst_t *temp, *found;

	if (!tree)
		return (NULL);

	temp = tree;
	while (temp)
	{
		if (temp->n > value)
			temp = temp->left;
		else if (temp->n < value)
			temp = temp->right;
		else
		{
			found = temp;
			return ((bst_t *)found);
		}
	}
	return (NULL);
}

		

/**
 * bst_search - searches BST for a value
 * @tree: pointer to the root of the teee
 * @value: value we want to search in the node
 *
 * Return: pointer to the node containtaining, else NULL
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *search;

	if (!tree)
		return (NULL);
	search = search_value(tree, value);
	return (search);
}
