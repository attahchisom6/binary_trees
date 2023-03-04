#include "binary_trees.h"
#include "limits.h"

/**
 * bst_analyser - analyzed a binary tree to check if it met
 * the conditions of a BST (binary search tree)
 * @min: the lowest value of nodes in a binary tree
 * @max: the maximum value of nodes contained in a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if conditions are met, else 0
 */

int bst_analyser(const binary_tree_t *tree, int min, int max)
{
	int analyser;

	/*an empty tree is also a BST*/
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	analyser = bst_analyser(tree->left, min, tree->n - 1)
		&& bst_analyser(tree->right, tree->n + 1, max);

	return (analyser);
}

/**
 * binary_tree_is_bst - checks if a given tree is a bst tree
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if it is a BST, else 0
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bst_analyser(tree, INT_MIN, INT_MAX));
}
