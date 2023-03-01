#include "binary_trees.h"

/**
 * binary_tree_is_leaf - check if a node is a leaf
 * @tree: pointer to the root of the tree
 *
 * Return: 1 ig its a root, else 0
 */

int binary_tree_is_leaf(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	return (0);
}

/**
 * binary_tree_leaves - counnt the number of leaves in binary tree
 * @tree: pointer to the root node
 *
 * Return: number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t count = 0;

	if (!tree)
		return (0);

	if (binary_tree_is_leaf(tree) != 0)
		return (1);
	count = binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right);

	return (count);
}
