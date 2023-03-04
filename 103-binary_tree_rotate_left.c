#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate a right inclined binary tree to
 * the left side
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to a new node that serve as the axis of rotation
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (!tree || !tree->right)
		return (NULL);

	new = tree->right;
	if (new->left)
	{
		tree->right = new->left;
		tree->right->parent = tree;
	}
	else
		tree->right = NULL;

	new->left = tree;
	new->parent = tree->parent;
	tree->parent = new;

	return (new);
}
