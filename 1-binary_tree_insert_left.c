#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node at the left side
 * of a binary tree
 * @parent: pointer to the parent of the created node
 * @value: value of the new node
 *
 * Return: pointer to the created node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *current;

	if (!parent)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (!new)
		return (NULL);
	if (parent->left != NULL)
	{
		parent->left->parent = new;
		new->left = parent->left;
	}
	parent->left = new;
	return (new);
}
