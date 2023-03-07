#include "binary_trees.h"

/**
 * inorder_successor - searches the left subtree of a tree or
 * subtree to obtaint the minimum value
 * @root: pointer to the root node of the tree
 *
 * Return: pointer to the node with the min value
 */

bst_t *inorder_successor(bst_t *root)
{
	bst_t *successor = root;

	while (successor->left)
		successor = successor->left;
	return (successor);
}

/**
 * node_destroyer - removes a node with a given value
 * @value: value contained by the node to destroy
 * @root: pointer to the root node
 * @node: pointer to the node to destroy
 *
 * return: pointer to the new root
 */

bst_t *node_destroyer(bst_t *root, bst_t *node)
{
	bst_t *temp, *parent;

	parent = node->parent;

	/*node has doesn't have a left child*/
	if (!node->left)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);

		return (!parent ? node->right : root);
	}
	/*node doesn't have a right child*/
	else if (!node->right)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);

		return (!parent ? node->left : root);
	}
	/*if node has two children*/
	temp = inorder_successor(node->right);
	node->n = temp->n;

	return (node_destroyer(root, temp));
}

/**
 * bst_remove - remove a node with a given value from aBST
 * @root: pointer to the root node
 * @valuel: value contained in the node
 *
 * Return: pointer to the new created root
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->left = bst_remove(root->right, value);
	else
	{
		node_destroyer(root, root);
	}

	return (NULL);
}
