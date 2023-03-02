#include "binary_trees.h"

/**
 * recursive_depth - estimates the distance ofa node from the root node
 * @tree: pointer to the root node ot the tree
 *
 * Return: recursive depth of the tree
 */

size_t recursive_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (!tree)
		return (-1);

	depth = recursive_depth(tree->parent);
	return (depth + 1);
}

/**
 * get_depth - gets the actual value of the depth
 * @tree:pointer to the root node
 *
 * Return: real depth of the tree
 */

size_t get_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (recursive_depth(tree));
}

/**
 * binary_trees_ancestor - gets the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the root node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t right, left;
	binary_tree_t *ancestor;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	left = get_depth(first);
	right = get_depth(second);

	if (left > right)
	{
		ancestor = binary_trees_ancestor(first->parent, second);

		return (ancestor);
	}

	else if (right > left)
	{
		ancestor = binary_trees_ancestor(first, second->parent);

		return (ancestor);
	}
	ancestor = binary_trees_ancestor(first->parent, second->parent);

	return (ancestor);
}
