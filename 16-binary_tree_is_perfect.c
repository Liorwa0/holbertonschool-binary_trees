#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_h = 0;
	size_t right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + binary_tree_height(tree->left);
	else
		left_h = 0;

	if (tree->right)
		right_h = 1 + binary_tree_height(tree->right);
	else
		right_h = 0;

	if (left_h > right_h)
		return (left_h);
	return (right_h);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_h, right_h;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height(tree->left);
	right_h = binary_tree_height(tree->right);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left && tree->right)
	{
		return (left_h == right_h &&
			binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right));
	}

	return (0);
}
