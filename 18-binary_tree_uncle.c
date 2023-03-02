#include "binary_trees.h"

/**
 * binary_tree_sibling - function that checks if a node has a sibling
 * @node: pointer to the node to check
 *
 * Return: 1 if it has a sibling, else 0
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent, *sibling;

	if (!node)
		return (NULL);

	parent = node->parent;
	if (parent != NULL)
	{
		if (node == parent->left)
		{
			sibling = parent->right;
			return (sibling);
		}

		else if (node == parent->right)
		{
			sibling = parent->left;
			return (sibling);
		}
		return (NULL);
	}
	return (NULL);
}

/**
 * binary_tree_uncle - get the uncle of a node, that is the sibling of its
 * parent
 * @node: node whose uncle is sought
 *
 * Return: pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *uncle;

	if (!node)
		return (NULL);

	parent = node->parent;
	if (!parent)
		return (NULL);

	uncle = binary_tree_sibling(parent);
	if (!uncle)
		return (NULL);

	return (uncle);
}
