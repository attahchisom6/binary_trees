#include "binary_trees.h"

/**
 * get_height - gets the height of a binary tree
 * @tree: pointer to the root node
 *
 * Return: estimated height of the tree
 */

int get_height(const binary_tree_t *tree)
{
	int left = 1, right = 1;

	if (!tree)
		return (0);

	left = get_height(tree->left);
	right = get_height(tree->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * avl_analyser - analyzed a binary tree to check if it met
 * the conditions of a BST (binary search tree)
 * @min: the lowest value of nodes in a binary tree
 * @max: the maximum value of nodes contained in a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if conditions are met, else 0
 */

int avl_analyser(const binary_tree_t *tree, int min, int max)
{
	int analyser;
	int left_h, right_h, diff;

	/*an empty tree is also a BST*/
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	left_h = get_height(tree->left);
	right_h = get_height(tree->right);
	if (left_h > right_h)
		diff = left_h - right_h;
	else
		diff = right_h - left_h;
	if (diff > 1)
		return (0);

	analyser = avl_analyser(tree->left, min, tree->n - 1)
		&&
		avl_analyser(tree->right, tree->n + 1, max);

	return (analyser);
}

/**
 * binary_tree_is_avl - checks if a given tree is a bst tree
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if it is a BST, else 0
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (avl_analyser(tree, INT_MIN, INT_MAX));
}
