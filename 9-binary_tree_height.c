#include "binary_trees.h"

/**
 * get_tree_height - recursive function to estimate the height of a tree
 * @tree: root of the tree
 *
 * Return: estimate of the height else 0
 */

size_t get_tree_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (0);

	left = get_tree_height(tree->left);
	right = get_tree_height(tree->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * binary_tree_height - get the height of the a binary tree
 * @tree: eoot of the tree
 *
 * Return: height of the tree else 0
 */

size_t binary_tree_height(binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (get_tree_height(tree) - 1);
}
