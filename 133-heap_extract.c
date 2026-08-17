#include "binary_trees.h"

/**
 * tree_size_h - Computes the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_size_h(tree->left) + tree_size_h(tree->right) + 1);
}

/**
 * get_last_node - Gets the last level-order node
 * @root: Pointer to the root node
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	size_t nodes = tree_size_h(root);
	size_t bit;
	heap_t *last = root;

	for (bit = 1; bit <= nodes; bit <<= 1)
		;
	bit >>= 2;

	while (bit > 0)
	{
		if (nodes & bit)
			last = last->right;
		else
			last = last->left;
		bit >>= 1;
	}
	return (last);
}

/**
 * heapify_down - Restores the Max Heap property top-down
 * @root: Pointer to the root node
 */
void heapify_down(heap_t *root)
{
	heap_t *max;
	int temp;

	while (root->left)
	{
		max = root->left;
		if (root->right && root->right->n > max->n)
			max = root->right;
		if (max->n > root->n)
		{
			temp = root->n;
			root->n = max->n;
			max->n = temp;
			root = max;
		}
		else
			break;
	}
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node
 * Return: Value of the extracted node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last_node;

	if (!root || !*root)
		return (0);
	value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	last_node = get_last_node(*root);
	(*root)->n = last_node->n;
	if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;
	free(last_node);
	heapify_down(*root);
	return (value);
}
