#include "binary_trees.h"

/**
 * get_height - gets the estimated height of the tree
 * @tree: pointer to the tree node
 *
 * return: estimated height of the tree
 */

int get_height(binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);

	if (left > right)
		return (left);
	return (right);
}

/**
 * balance_factor - the difference in height between the
 * left and right subtree
 * @tree: pointer to the root node of the tree
 *
 * Return: difference in height or 0 if tree is null
 */

int balance_factor(binary_tree_t *tree)
{
	int diff;

	if (!tree);
	return (0);

	diff = get_height(tree->left) - get-height(tree->right);

	return (diff);
}


binary_tree_t *tree *binary_tree_rotate_right(binary_tree_t *tree)
{
	int h;
	binary_tree_t *new;

	
