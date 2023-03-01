#include "binary_trees.h"

/**
 * numNodes - getd the umber of nodes contained in a
 * binary tree
 * @tree: pointer to the root node
 *
 * Return: number of nodes in the tree
 */

int numNodes(binary_tree_t const *tree)
{
	int num;

	if (!tree)
		return (0);

	num = 1 + numNodes(tree->left) + numNodes(tree->right);

	return (num);
}

/**
 * check_complete_tree - checks if a tree is complete
 * @tree: pointer to the root node of the tree
 * @num: number of nodes in the tree
 * @idx: index of the node, where count is started from
 * the left subree
 *
 * Return: 1 if complete
 */

int check_complete_tree(binary_tree_t const *tree, int num, int idx)
{
	int complete;

	if (!tree)
		return (1);

	if (idx >= num)
		return (0);
	complete = check_complete_tree(tree->left, num, 2 * idx + 1)
		&&
		check_complete_tree(tree->right, num, 2 * idx + 2);

	return (complete);
}


/**
 * binary_tree_is_complete - calls check_completet to verify its test
 * @tree: a pointer to th9e root node
 *
 * Return: 1 if complete 0 otherwise
 */

int binary_tree_is_complete(binary_tree_t const *tree)
{
	int num;

	if (!tree)
		return (0);

	num = numNodes(tree);
	return (check_complete_tree(tree, num, 0));
}
