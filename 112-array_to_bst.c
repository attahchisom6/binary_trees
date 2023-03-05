#include "binary_trees.h"

/**
 * array_to_bst - builds a binary tree from an array
 * @array: pointer to the first element in the array
 * @size: number of elements in the array
 *
 * Return: pointer to the root of the tree
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t k;

	if (!array)
		return (NULL);

	k = 0;
	while (k < size)
	{
		bst_insert(&tree, array[k]);
		k++;
	}

	return (tree);
}
