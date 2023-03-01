#include "binary_trees.h"

/**
 * binary_tree_postorder - function to transverse the left, then tranverse the right
 * then display it
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function whose parameter is the value contained
 * in the  node
 *
 * Return: void
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
