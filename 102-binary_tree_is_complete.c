#include "binary_trees.h"

/**
 * count_nodes - Counts total number of nodes in a binary tree
 * @tree: Pointer to root node
 *
 * Return: Total number of nodes
 */
static size_t count_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + count_nodes(tree->left) + count_nodes(tree->right));
}

/**
 * is_complete_rec - Recursively checks if binary tree is complete
 * @tree: Pointer to current node
 * @index: Index of current node
 * @total: Total number of nodes in the tree
 *
 * Return: 1 if complete, 0 otherwise
 */
static int is_complete_rec(const binary_tree_t *tree,
			   size_t index, size_t total)
{
	if (tree == NULL)
		return (1);

	if (index >= total)
		return (0);

	return (is_complete_rec(tree->left, 2 * index + 1, total) &&
		is_complete_rec(tree->right, 2 * index + 2, total));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if complete, 0 otherwise or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t total;

	if (tree == NULL)
		return (0);

	total = count_nodes(tree);
	return (is_complete_rec(tree, 0, total));
}
