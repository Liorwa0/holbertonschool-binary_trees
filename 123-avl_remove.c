#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the minimum value
 * @node: Pointer to the root of the tree
 *
 * Return: Pointer to the minimum value node
 */
avl_t *min_value_node(avl_t *node)
{
	avl_t *current = node;

	while (current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove
 *
 * Return: Pointer to the new root node
 */
avl_t *bst_remove(avl_t *root, int value)
{
	avl_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
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
			return (temp);
		}
		temp = min_value_node(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	if (root->left)
		root->left->parent = root;
	if (root->right)
		root->right->parent = root;
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node
 */
avl_t *avl_remove(avl_t *root, int value)
{
	int b_factor;

	if (root == NULL)
		return (NULL);
	root = bst_remove(root, value);
	if (root == NULL)
		return (NULL);
	b_factor = binary_tree_balance(root);
	if (b_factor > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));
	if (b_factor > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}
	if (b_factor < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));
	if (b_factor < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}
