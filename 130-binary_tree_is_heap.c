#include "binary_trees.h"

/**
 * numNodes - gets the total number of nodes in a binary tree
 * @tree: pointer to the root node
 *
 * Return: total number of nodes in the tree
 */

size_t numNodes(const binary_tree_t *tree)
{
	size_t nNodes;

	if (!tree)
		return (0);

	nNodes = 1 + numNodes(tree->left) + numNodes(tree->right);

	return (nNodes);
}

/**
 * is_tree_complete - chwcks whether a tree is complete
 * @tree: pointer to the root node
 * @idx: index of each node if read into an array
 * @nNodes: total number of nodes in the tree
 *
 * Return: 1 if tree is comolete, 0 otherwise
 */

int is_tree_complete(const binary_tree_t *tree, size_t idx, size_t nNodes)
{
	/*an empty node is a complete tree*/
	if (!tree)
		return (1);

	if (idx >= nNodes)
		return (0);

	return (is_tree_complete(tree->left, 2 * idx + 1, nNodes)
			&& is_tree_complete(tree->right, 2 * idx + 2, nNodes));
}

/**
 * call_tree_complete - call the is tree complete function
 * @tree: pointer to the root node
 *
 * Return: 1 on success, 0 on aiure
 */

int call_tree_complete(const binary_tree_t *tree)
{
	size_t nNodes, idx = 0;

	nNodes = numNodes(tree);

	return (is_tree_complete(tree, idx, nNodes));
}

/**
 * chk_parent - check if the value contained in a node is greater than that of
 * its children
 * @tree: pointer to the root nodes
 *
 * Return: 1 if true, else false
 */

int chk_parent(const binary_tree_t *tree)
{
	/*NULL node may have a non node parent*/
	if (!tree)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (chk_parent(tree->left) && chk_parent(tree->right));
}

/**
 * binary_tree_is_heap - checks if a binary tree is a max heap tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 true, 0 otherwise
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int k = call_tree_complete(tree);

	if (!tree)
		return (0);

	if (k == 0)
		return (0);
	return (chk_parent(tree->left) && chk_parent(tree->right));
}
