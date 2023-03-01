#include "binary_trees.h"

/**
 * binary_tree_delete - deletes all elements in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: void
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);
	free(tree);
}
