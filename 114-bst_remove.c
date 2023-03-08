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
 * @root: pointer to the root node
 * @node: pointer to the node to destroy
 *
 * Return: pointer to the new root
 */

bst_t *node_destroyer(bst_t *root, bst_t *node)
{
	bst_t *temp = NULL, *parent;

	parent = node->parent;

	/*node doesn't have a left child*/
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
 * remove_recursion - recusively remove a node from a BST
 * @root: pointer to the root node
 * @node: node to remove
 * @value: value contained in the node we to remove
 *
 * Return: pointer to the new root
 */

bst_t *remove_recursion(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (value < node->n)
			return (remove_recursion(root, node->left, value));
		else if (value > node->n)
			return (remove_recursion(root, node->right, value));
		return (node_destroyer(root, node));
	}
	return (NULL);
}

/**
 * bst_remove - remove a node with a given value from aBST
 * @root: pointer to the root node
 * @value: value contained in the node
 *
 * Return: pointer to the new created root
 */

bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_recursion(root, root, value));
}
