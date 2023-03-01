#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node at the right hand side
 * of the binary tree
 * @parent:pointer to the parent of the created node
 * @value: value of the new created node
 *
 * Return: pointer to the new created node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);
	if (parent->right != NULL)
	{
		parent->right->parent = new;
		new->right = parent->right;
	}
	parent->right = new;
	return (new);
}
