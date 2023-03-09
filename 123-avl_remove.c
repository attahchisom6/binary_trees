#include "binary_trees.h"

/**
 * avl_tree_balancerr - balances a root into an avl root
 * @root: pointer to the root node of the root
 * @value: value contained in the nose
 *
 * Return: void
 */

void avl_tree_balancerr(avl_t **root, int value)
{
	int bfactor;

	if (!root || !*root)
		return;
	if (!(*root)->left || !(*root)->right)
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

avl_t *inorder_successor(avl_t *root)
{
	avl_t *successor;

	successor = root;
	while (successor->left)
		successor = successor->left;

	return (successor);
}

/**
 * delete_node - deletes a node whose with a specified value
 * @root: pointer to the root node of the root
 * @node: pointer to the node we want to delete
 *
 * Return: pointer to the new root
 */

avl_t *delete_node(avl_t *root, avl_t *node)
{
	avl_t *successor = NULL, *parent = node->parent;

	if (node)
	{
		/*node has no right child*/
		if (!node->left)
		{
			if (parent->right == node)
				parent->right = node->right;
			else if (parent->left == node)
				parent->left = node->right;
			if (node->right)
				node->right->parent = parent;
			free(node);

			return (!parent ? node->right : root);
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

			return (!parent ? node->left: root);
		}
		
		/*node has two children*/
		successor = inorder_successor(node->right);
		node->n = successor->n;

		return (delete_node(root, successor));
	}
	return (root);
}

/**
 * search_remove - recursively search and remove a desired node
 * from an avl
 * @root: pointer to the root node
 * @node: node to remove
 * @value: value of the node to remove
 *
 * Return: oointer to the new root
 */

avl_t *search_remove(avl_t *root, avl_t *node, int value)
{
	if (!root)
		return (NULL);

	if (!node)
		return (NULL);

	if (value < node->n)
		return (search_remove(root, node->left, value));
	else if (value > node->n)
		return (search_remove(root, node->right, value));
	return (delete_node(root, node));
}

/**
 * avl_remove - removes a node from an avl tree
 * root: pointer to the root node
 * @value: value contained in the node to delete
 *
 * Return: ointer pointer to the new root
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *mroot = NULL;

	mroot = search_remove(root, root, value);
	if (mroot)
		avl_tree_balancerr(&root, value);
	return (mroot);
}
