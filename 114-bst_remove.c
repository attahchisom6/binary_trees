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
 * @node: pointer to the node to destroy
 *
 * return: pointer to the new root
 */

bst_t *node_destroyer(bst_t *node, value)
{
	bst_t *temp, *parent;

	parent = node->parent;
	while (parent)
	{
		/*node has doesn't have a left child*/
		if (!node->left)
		{
			if (parent->left == node)
				parent->left = node->right;
			else
				parent->right = node->right;
			if (node->right)
				node->right->parent = parent;
			free(node);
		}
		/*node doesn't have a right child*/
		else if (!node->right)
		{
			if (parent->left == node)
				parent->left = node->left;
			else
				parent->right = node->left;
			if (node->left)
				node->left->parent = parent;
			free(node);
		}
		/*if node has two children*/
		temp = node_destroyer(node->right, value);
		root-> = temp->;
