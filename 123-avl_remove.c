#include "binary_trees.h"

/**
 * inorder_successor - returns the minimum value of a binary search tree
 * @tree: pointer to the root node of the tree to search
 * Return: minimum value
 */
avl_t *inorder_successor(avl_t *tree)
{
	while (tree->left != NULL)
		tree = tree->left;
	return (tree);
}

/**
 * avl_rebalance - rebalances an AVL tree
 * @root: pointer to root
 * Return: pointer to new root
 */
avl_t *avl_rebalance(avl_t *root)
{
	int b_factor;

	b_factor = binary_tree_balance(root);
	if (b_factor > 1 && binary_tree_balance(root->left) >= 0)
		root = binary_tree_rotate_right(root);
	else if (b_factor > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		root = binary_tree_rotate_right(root);
	}
	else if (b_factor < -1 && binary_tree_balance(root->right) <= 0)
		root = binary_tree_rotate_left(root);
	else if (b_factor < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		root = binary_tree_rotate_left(root);
	}
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				free(root);
				return (NULL);
			}
			temp->parent = root->parent;
			free(root);
			root = temp;
		}
		else
		{
			temp = inorder_successor(root->right);
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	return (avl_rebalance(root));
}
