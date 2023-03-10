#include "binary_trees.h"

/**
 * create_avl_tree  - creates an avl tree from an array
 * @tree: root of the avl treee
 * @array: pointer to the first element of the array
 * @start: startiing point of the array
 * @end: end point of the array
 *
 * Return: pointer to the root node created
 */

avl_t *create_avl_tree(avl_t *tree, int *array, int start, int end)
{
	avl_t *root = NULL;
	int mid = 0;

	if (start < end)
	{
		mid = (start + end) / 2;
		root = binary_tree_node(tree, array[mid]);
		if (!root)
			return (NULL);

		root->left = create_avl_tree(root, array, start, mid - 1);
		root->right = create_avl_tree(root, array, mid + 1, end);

		return (root);
	}

	return (NULL);
}

/**
 * sorted_array_to_avl - create an avl tree from a sorted array
 * @array: pointer to the array
 * @size: size of elements un the array
 *
 * Return: pointer to the root the craeted avl array
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl_tree = NULL;

	if (!array || size == 0)
		return (NULL);

	avl_tree = create_avl_tree(NULL, array, 0, size - 1);
	return (avl_tree);
}
