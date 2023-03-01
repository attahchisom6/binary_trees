#include "binary_trees.h"

/**
 * binary_tree_preorder - display root, then keft and finally right;
 * @tree: pointer to the root node of the tree to transverse
 * @func: pointer to function who takes as parameter the value in the node
 *
 * Return: void
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
