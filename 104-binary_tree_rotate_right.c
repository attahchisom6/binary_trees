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
	int bf;
	binary_tree_t *new;

	if (!tree)
		return (NULL);

	/*bf = balance_factor(tree);
	if (bf > 1)
	{*/
	new = tree->left;
		
	tree->left = new->right;
	new->right = tree;
	tree->parent = new;

	return (new);
	/*}
	return (NULL);*/
}
