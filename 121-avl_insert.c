#include "binary_trees.h"

/**
 * avl_tree_balancer - balances a tree to obtain avl tree
 * @tree: pointer to the root of the tree
 * @value: value contained in the node to balance
 *
 * Return: pointer to the the new created node root
 */

avl_t *avl_tree_balancer(avl_t **tree, int value)
{
	avl_t *node;
	int bfactor;

	/*if (!tree)
		return (NULL);*/

	node = *tree;
	bfactor = binary_tree_balance(node);
	/**LEFT LEFT case*/
	if (bfactor > 1 && value < node->left->n)
		return (binary_tree_rotate_right(node));
	/*LEFT RIGHT CASE*/
	if (bfactor > 1 && value > node->left->n)
	{
		node->left = binary_tree_rotate_left(node->left);
		return (binary_tree_rotate_right(node));
	}

	/*RIGHT RIGHT case*/
	if (bfactor < -1 && value > node->right->n)
		return (binary_tree_rotate_left(node));

	/**RIGHT LEFT case*/
	if (bfactor < -1 && value < node->right->n)
	{
		node->right = binary_tree_rotate_right(node->right);
		return (binary_tree_rotate_left(node));
	}
	return (node);
}

/**
 * avl_sort_insert - sort or decide in which order element are inserted
 * in the avl tree
 * @tree: double pointer to the root node
 * @value: valued held by each node in the tree
 *
 * Return: pointer to the new root
 */

avl_t *avl_sort_insert(avl_t **tree, int value)
{
	avl_t *root, *new, *neww;

	/*if (!root)
		return (NULL);*/

	root = *tree;
	while (root)
	{
		if (value < root->n)
		{
			if (!root->left)
			{
				root->left = binary_tree_node(root, value);

				return (root->left);
			}
			else
			{
				new = avl_sort_insert(&root->left, value);
				if (new)
					neww = avl_tree_balancer(&root, value);

				return (neww);
			}
		}
		if (value > root->n)
		{
			if (!root->right)
			{
				root->right = binary_tree_node(root, value);

				return (root->right);
			}
			else
			{
				new = avl_sort_insert(&root->right, value);
				if (new)
					neww = avl_tree_balancer(&root, value);

				return (neww);
			}
		}
		return (*tree);
	}
	return (NULL);
}

/**
 * avl_insert -inserts a node in an avl tree
 * @tree: double pointer to the the root node
 * @value: value contained in the node to insert
 *
 * Return: pointer to the new root created
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);

		return (*tree);
	}
	else
		return (avl_sort_insert(tree, value));
	return (NULL);
}
