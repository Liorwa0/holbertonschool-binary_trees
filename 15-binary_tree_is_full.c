#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is full, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* إذا كانت العقدة ورقة (ليس لها أبناء يمين أو يسار) */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* إذا كان للعقدة ابنان، نتحقق من الفرعين بشكل تكراري */
	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	/* إذا كان لها ابن واحد فقط، فالشجرة ليست ممتلئة */
	return (0);
}
