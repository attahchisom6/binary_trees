#include "binary_trees.h"

/**
 * array_to_avl - converts an an array to an avl tree
 * @array: pointer to the first element in the array
 * @size: nmber of elements in the array
 *
 * Return: pointer to the root node of the created avl tree
 */

avl_t *array_to_avl(int *array, size_t size)
{
	size_t k = 0;
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	while (k < size)
	{
		avl_insert(&tree, array[k]);

		k++;
	}

	return (tree);
}
