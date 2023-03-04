#include "binary_trees.h"

/*"
 * binary_tree_rotate_right - rotates a binary tree thats left inclined
 * to the right side
 * @tree: pionter to the root node
 *
 * Return: Pointer to the new node that should be an anchor for rotation
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (!tree || !tree->left)
		return (tree);

	new = tree->left;
	tree->left = new->right;
	new->right = tree;
	tree->parent = new;

	return (new);
}
