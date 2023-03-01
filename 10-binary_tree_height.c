#include "binary_trees.h"

/**
 * get_tree_depth - recursive function to estimate the depth of a tree
 * @tree: root of the tree
 *
 * Return: estimate of the depth else 0
 */

size_t get_tree_depth(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (-1);

	return (get_tree_depth(tree->parent) + 1);
}

/**
 * binary_tree_depth - get the depth of the a binary tree
 * @tree: eoot of the tree
 *
 * Return: depth of the tree else 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (get_tree_depth(tree));
}
