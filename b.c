#include "binary_trees.h"

/**
 * avl_tree_balancerr - balances a root into an avl root
 * @root: pointer to the root node
 * @value: value occupied by the thaat will form the axis
 * of rotation
 *
 * Return: void
 */

void avl_tree_balancerr(avl_t **root, int value)
{
	int bfactor;

	if (!root || !*root)
		return;
	if (!(*root)->left && !(*root)->right)
		return;
	avl_tree_balancerr(&(*root)->left, value);
	avl_tree_balancerr(&(*root)->right, value);

	bfactor = binary_tree_balance(*root);
	if (bfactor > 1)
		*root = binary_tree_rotate_right(*root);
	else if (bfactor < -1)
		*root = binary_tree_rotate_left(*root);
}

/**
 * inorder_successor - search along the left side of a subroot for the
 * node with minimum value
 * @root: pointer to the root node of the root
 *
 * Return: pointer to the node with least value
 */

int inorder_successor(avl_t *root)
{
	int successor;

	if (!root)
		return (0);

	successor = inorder_successor(root->left);
	if (!successor)
		return (root->n);
	return (successor);
}

/**
 * when_to_delete - deletes a node whose with a specified value
 * @node: pointer to the node we want to delete
 *
 * Return: pointer to the new root
 */

int when_to_delete(avl_t *node)
{
	int successor = 0;
	avl_t *parent = node->parent;

	if (node)
	{
		if (!node->left && !node->right)  /*node has no children*/
		{
			parent->right == node ? (parent->right = NULL) : (parent->left = NULL);
			free(node);
			return (0);
		}
		/*node has no left child*/
		if (!node->left)
		{
			if (parent->right == node)
				parent->right = node->right;
			else if (parent->left == node)
				parent->left = node->right;
			if (node->right)
				node->right->parent = parent;
			free(node);
			return (0);
		}
		/*node has no right child*/
		else if (!node->right)
		{
			if (parent->right == node)
				parent->right = node->left;
			else if (parent->left == node)
				parent->left = node->left;
			if (node->left)
				node->left->parent = parent;
			free(node);
			return (0);
		}
		/*node has two children*/
		successor = inorder_successor(node->right);
		node->n = successor;
		return (successor);
	} return (0);
}

/**
 * search_remove - recursively search and remove a desired node
 * from an avl
 * @node: node to remove
 * @value: value of the node to remove
 *
 * Return: oointer to the new root
 */

avl_t *search_remove(avl_t *node, int value)
{
	int when = 0;

	if (!node)
		return (NULL);

	if (value < node->n)
		search_remove(node->left, value);
	else if (value > node->n)
		search_remove(node->right, value);
	else
	{
		when = when_to_delete(node);

		if (when)
			search_remove(node->right, when);
	} return (node);
}

/**
 * avl_remove - removes a node from an avl tree
 * @root: pointer to the root node
 * @value: value contained in the node to delete
 *
 * Return: ointer pointer to the new root
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *mroot = NULL;

	mroot = search_remove(root, value);
	if (mroot)
		avl_tree_balancerr(&mroot, value);
	else
		return (NULL);
	return (mroot);
}
