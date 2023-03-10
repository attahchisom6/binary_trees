#include "binary_trees.h"

/**
 * avl_tree_balance - balances a (*root) into an avl (*root)
 * @(*root): pointer to the (*root) node of the (*root)
 * @value: value contained in the nose
 *
 * Return: void
 */

void avl_tree_balancerr(avl_t *(*root), int value)
{
	int bfactor;

	bfactor = binary_tree_balance((*root));

	/**LEFT LEFT CASE case*/
	if (bfactor > 1 && value < (*root)->left->n)
	{
		(*root) = binary_tree_rotate_right((*root));
		return;
	}

	/*LEFT RIGHT case*/
	if (bfactor > 1 && value > (*root)->left->n)
	{
		(*root)->left = binary_tree_rotate_left((*root)->left);
		(*root) = binary_tree_rotate_right((*root));
		return;
	}

	/*RIGHT RIGHT case*/
	if (bfactor < -1 && value > (*root)->right->n)
	{
		(*root) = binary_tree_rotate_left((*root));
		return;
	}

	/*RIGHT LEFT case*/
	if (bfactor < -1 && value < (*root)->right->n)
	{
		(*root)->right = binary_tree_rotate_right((*root)->right);
		(*root) = binary_tree_rotate_left((*root));
		return;
	}
}
