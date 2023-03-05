#include "binary_trees.h"

/**
 * inorder_successor - moves along the left subtrees of a tree
 * in search of a node with the lowrst value
 * @root: root of the tree
 *
 * Return: pointer to the node containing the minimum value in the tree
 */

bst_t *inorder_successor(bst_t *root)
{
	bst_t *successor;

	successor = root;
	while (successor->left)
		successor = successor->left;

	return (successor);
}

/**
 * bst_remove - removes a node with a given value in BST
 * @root: root of the tree
 * @value: to to seek and delete
 *
 * Return: pointer to the new created root after the node is delected
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);

			return (temp);
		}
		if (!root->right)
		{
			temp = root->left;
			free(root);

			return (temp);
		}
		temp = inorder_successor(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
