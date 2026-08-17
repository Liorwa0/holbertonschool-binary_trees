#include "binary_trees.h"

/**
 * bst_insert_avl - Helper function to insert a value into a BST
 * @tree: Double pointer to the root node of the BST
 * @parent: Parent node
 * @new_node: Double pointer to the new node
 * @value: Value to store in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *bst_insert_avl(avl_t **tree, avl_t *parent, avl_t **new_node, int value)
{
	if (*tree == NULL)
	{
		*new_node = binary_tree_node(parent, value);
		if (*new_node == NULL)
			return (NULL);
		*tree = *new_node;
		return (*new_node);
	}
	if (value < (*tree)->n)
	{
		(*tree)->left = bst_insert_avl(&(*tree)->left, *tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if (value > (*tree)->n)
	{
		(*tree)->right = bst_insert_avl(&(*tree)->right, *tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);
	return (*tree);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;
	int b_factor;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	bst_insert_avl(tree, *tree, &new_node, value);
	if (new_node == NULL)
		return (NULL);
	b_factor = binary_tree_balance(*tree);
	if (b_factor > 1 && value < (*tree)->left->n)
		*tree = binary_tree_rotate_right(*tree);
	else if (b_factor < -1 && value > (*tree)->right->n)
		*tree = binary_tree_rotate_left(*tree);
	else if (b_factor > 1 && value > (*tree)->left->n)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (b_factor < -1 && value < (*tree)->right->n)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (new_node);
}
