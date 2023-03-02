#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @tree: pointer to the root node
 *
 * Return: 1 if its a leaf, 0 otherwise
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
 * has_childNode - function to check if a node has at least one child
 * @tree: pointer to the root node
 *
 * Return: 1 if it has a child, 0 otherwise
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
 * binary_tree_is_full - check if every node in the tree has two child
 * @tree: pointer to the root node
 *
 * Return: 1 if full, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);
	if (binary_tree_is_leaf(tree) != 0)
		return (1);

	if (has_childNode(tree) != 0)
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		return (left && right);
	}
	return (0);
}
