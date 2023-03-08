#include "binary_trees.h"

/**
 * avl_tree_balancer - balances a tree to obtain avl tree
 * @tree: pointer to the root of the tree
 * @value: value contained in the (*tree) to balance
 *
 * Return: pointer to the the new created (*tree) root
 */

void avl_tree_balancer(avl_t **tree, int value)
{
	int bfactor;

	bfactor = binary_tree_balance((*tree));
	/**LEFT LEFT case*/
	if (bfactor > 1 && value < (*tree)->left->n)
	{
		*tree = binary_tree_rotate_right((*tree));
		return;
	}
	/*LEFT RIGHT CASE*/
	if (bfactor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_right((*tree)->left);
		binary_tree_rotate_right((*tree));
		return;
	}

	/*RIGHT RIGHT case*/
	if (bfactor < -1 && value > (*tree)->right->n)
	{
		*tree = binary_tree_rotate_right((*tree));
		return;
	}

	/**RIGHT LEFT case*/
	if (bfactor < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left((*tree));
		return;
	}
}


/**
 * avl_sort_insert - sort or decide in which order element are inserted
 * in the avl tree
 * @tree: double pointer to the (*tree) node
 * @value: valued held by each node in the tree
 *
 * Return: pointer to the new (*tree)
 */

avl_t *avl_sort_insert(avl_t **tree, int value)
{
	avl_t *new;

	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node((*tree)->left, value);

			return ((*tree)->left);
		}
		else
		{
			new = avl_sort_insert(&(*tree)->left, value);
			if (new)
				avl_tree_balancer(&new, value);

			return (new);
		}
	}
	if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node((*tree)->right, value);

			return ((*tree)->right);
		}
		else
		{
			new = avl_sort_insert(&(*tree)->right, value);
			if (new)
				avl_tree_balancer(&new, value);

			return (new);
		}
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
	return (avl_sort_insert(tree, value));
}
