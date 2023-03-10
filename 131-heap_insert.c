#include "binary_trees.h"

/**
 * binary_tree_size - gets the total number of nodes in a
 * binary tree
 * @tree: pointer to the root of the tree
 *
 * Return: total number of nodes in the tree
 */


size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}

/**
 * heap_insert - inserts a node into abinary tree
 * @root: double pointer to the root of the node
 * @value: vaue to savr in the inserted node
 *
 * Return: pointer to the new node
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *flip, *tree;
	int level, leaves, sub, temp, bit, size;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);

		return (*root);
	}

	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves = leaves - sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	while (flip)
	{
		if (flip->parent && flip->n > flip->parent->n)
		{
			temp = flip->n;
			flip->n = flip->parent->n;
			flip->parent->n = temp;

			new = new->parent;
		}
		flip = flip->parent;
	}
	return (new);
}
