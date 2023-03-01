#include "binary_trees.h"

/**
 * binary_tree_leaves - counnt the number of leaves in binary tree
 * @tree: pointer to the root node
 *
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count;

	if (!tree)
		return (0);

	if (binary_tree_is_leaf(tree) != 0)
		return (1);
	count = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (count);
}
