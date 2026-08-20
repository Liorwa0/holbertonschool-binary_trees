#include "binary_trees.h"

/**
 * inorder_successor - Finds the minimum node in a BST subtree
 * @root: Pointer to the root of the subtree
 *
 * Return: Pointer to minimum node
 */
static bst_t *inorder_successor(bst_t *root)
{
	while (root && root->left)
		root = root->left;
	return (root);
}

/**
 * bst_delete_node - Handles pointer updates and deletion of a node
 * @root: Pointer to root of the tree
 * @node: Pointer to the node to remove
 *
 * Return: Pointer to the new root node of the tree
 */
static bst_t *bst_delete_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL, *child = NULL;

	if (node->left == NULL || node->right == NULL)
	{
		child = node->left ? node->left : node->right;
		if (child)
			child->parent = parent;
		if (parent == NULL)
			root = child;
		else if (parent->left == node)
			parent->left = child;
		else
			parent->right = child;
		free(node);
		return (root);
	}

	successor = inorder_successor(node->right);
	node->n = successor->n;
	return (bst_delete_node(root, successor));
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = root;

	if (root == NULL)
		return (NULL);

	while (node)
	{
		if (value == node->n)
			return (bst_delete_node(root, node));
		else if (value < node->n)
			node = node->left;
		else
			node = node->right;
	}

	return (root);
}
