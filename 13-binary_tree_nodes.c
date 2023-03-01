#include "binary_trees.h"

/**
 * has_childNode - check for nodes that have at least one child
 * @tree: pointer to the root
 *
 * Return: 1 if has one or more child else 0
 */

int has_childNode(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left || tree->right)
		return (1);
	return (0);
}

/**
 * binary_tree_nodes - count of nodes that have at least one child
 * @tree: pointer to the root node
 *
 * Return: number of nodes with at least one child else 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count;

	if (!tree)
		return (0);

	if (has_childNode(tree) != 0)
	{
		count = binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1;
		return (count);
	}
	return (0);
}
