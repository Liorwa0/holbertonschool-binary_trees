#include "binary_trees.h"

/**
 * heap_size - Returns the size of a binary tree
 * @tree: Pointer to the root node
 * Return: Size of the tree
 */
size_t heap_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + heap_size(tree->left) + heap_size(tree->right));
}

/**
 * get_insert_parent - Finds the parent node for insertion
 * @root: Pointer to the root node
 * Return: Pointer to the parent node
 */
heap_t *get_insert_parent(heap_t *root)
{
	int nodes = heap_size(root) + 1;
	int parent_idx = nodes / 2;
	int bit;
	heap_t *parent = root;

	for (bit = 1; bit <= parent_idx; bit <<= 1)
		;
	bit >>= 2;

	while (bit > 0)
	{
		if (parent_idx & bit)
			parent = parent->right;
		else
			parent = parent->left;
		bit >>= 1;
	}
	return (parent);
}

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	int temp;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	parent = get_insert_parent(*root);
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		temp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = temp;
		new_node = new_node->parent;
	}
	return (new_node);
}
