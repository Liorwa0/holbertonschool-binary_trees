#include "binary_trees.h"
#include <limits.h>

/**
 * tree_height - Computes the height of a binary tree
 * @tree: Pointer to the root node
 *
 * Return: Height of tree, or 0 if NULL
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * is_avl_helper - Helper function to check if tree satisfies AVL properties
 * @tree: Pointer to the node
 * @min: Minimum valid value
 * @max: Maximum valid value
 *
 * Return: 1 if valid AVL, 0 otherwise
 */
static int is_avl_helper(const binary_tree_t *tree, int min, int max)
{
	size_t left_h, right_h, diff;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);
	diff = left_h > right_h ? left_h - right_h : right_h - left_h;

	if (diff > 1)
		return (0);

	return (is_avl_helper(tree->left, min, tree->n) &&
		is_avl_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise or if tree is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
