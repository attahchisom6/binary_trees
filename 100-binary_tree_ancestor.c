#include "binary_trees.h"

/**
 * binary_tree_sibling - function that checks if a node has a sibling
 * @node: pointer to the node to check
 *
 * Return: 1 if it has a sibling, else 0
 */

binary_tree_t *binary_tree_siblingg(const binary_tree_t *node)
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

binary_tree_t *binary_tree_unclee(const binary_tree_t *node)
{
	binary_tree_t *parent, *uncle;

	if (!node)
		return (NULL);

	parent = node->parent;
	if (!parent)
		return (NULL);

	uncle = binary_tree_siblingg(parent);
	if (!uncle)
		return (NULL);

	return (uncle);
}

/**
 * binary_trees_ancestor - gets the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the ancestor of both nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t const *ancestor;
	binary_tree_t *left, right;

	/*if (first == binary_tree_siblingg(second))
	{
		ancestor = first->parent;
		return ((binary_tree_t *)ancestor);
	}
	else if (first == binary_tree_unclee(second))
	{
		ancestor = first->parent;
		return ((binary_tree_t *)ancestor);
	}*/
	/*else
	{*/
	left = binary_trees_ancestor(first->parent, second);
	right = binary_trees_ancestor(first, second->parent);

	if (left == right)
		(binary_tree_ancestor *)ancestor = left;

	return ((binary_tree_t *)ancestor);

	/*return (NULL);*/
}
