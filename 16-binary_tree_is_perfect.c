#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if a node is a leaf in a binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: 1 if it's a leaf, else 0
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
 * has_childNode - checks if a node has a at one child
 * @tree: pointer to the root node
 *
 * Return: 1 if has at one child, else 0
 */

int has_childNode(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->right || tree->left)
		return (1);
	return (0);
}

/**
 * height - estimate the height of a tree, which being the distance
 * btwn rhe farthest node edge and the root
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, else 0
 */

int height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);

	left = height(tree->left);
	right = height(tree->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * binary_tree_is_perfect - check if every node in the tree is has two
 * children and the nodes are are height balance in each arm of the tree
 * @tree: pointer to rhe root node
 *
 * Return: 1 if perfecf, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left = 0, right = 0;

	if (!tree)
		return (0);

	if (height(tree->left) == height(tree->right))
	{
		if (binary_tree_is_leaf(tree) != 0)
			return (1);
		if (has_childNode(tree) != 0)
		{
			left = binary_tree_is_perfect(tree->left);
			right = binary_tree_is_perfect(tree->right);

			return (left && right);
		}
	}
	return (0);
}
