#include "binary_trees.h"

/**
 * recursive_height - get the recursive height of the tree
 * @tree: pointer to the root node
 *
 * Return: recursive of the tree
 */

size_t re_height(binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	left = re_height(tree->left);
	right = re_height(tree->right);

	if (left > right)
		return (left + 1);
	return (right + 1);
}

/**
 * print_level - prints all nodes in the same level
 * @tree: pointer to the toot of the tree
 * @level: each level or heihht of the tree
 * the tree
 * @func: function that accepts as a parameter the value stored in in each
 * node
 *
 * Return: void
 */

void print_level(binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (!tree || !func)
		return;

	if (level == 1)
		func(tree->n);

	if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - prints all nodes availaible at each level of
 * the tree
 * @tree: pointer to the root of the tree
 * @func: pointer to a function whose parameter is the value contained in
 * each node
 */

void binary_tree_levelorder(binary_tree_t *tree, void (*func)(int))
{
	size_t h, k;

	if (!tree || !func)
		return;

	h = re_height(tree);
	for (k = 0; k <= h; k++)
		print_level(tree, k, func);
}
