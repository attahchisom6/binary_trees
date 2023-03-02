#include "binary_trees.h"

/**
 * get_height - estimate the height of tree
 * @tree: pointer to the root of the the root of the tree
 *
 * Return: estimated height
 */

int get_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (!tree)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * height - get the actual height of the tree
 * @tree: pointer to the root node
 *
 * Return: actual height of the tree
 */

int height(const binary_tree_t *tree)
{
	if (!tree)
		return (-1);

	return (get_height(tree) - 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * know that nalance factor is the diffencce between height of the left
 * subtree and the right subtree
 * @tree: pointer to the root of the roor of the tree
 *
 * Return: value of the balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int bf;

	if (!tree)
		return (0);

	bf = height(tree->left) - height(tree->right);

	return (bf);
}
