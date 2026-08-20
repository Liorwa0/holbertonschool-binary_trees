#include "binary_trees.h"

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
 * print_at_level - Performs operation on nodes at a specific level
 * @tree: Pointer to the node
 * @func: Pointer to function to call
 * @level: Target level
 */
static void print_at_level(const binary_tree_t *tree,
			   void (*func)(int), size_t level)
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_at_level(tree->left, func, level - 1);
		print_at_level(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;

	height = tree_height(tree);
	for (i = 1; i <= height; i++)
		print_at_level(tree, func, i);
}
