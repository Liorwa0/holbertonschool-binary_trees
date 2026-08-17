#include "binary_trees.h"

/**
 * build_avl - Recursively builds an AVL tree from a sorted array
 * @parent: Pointer to the parent node
 * @array: Pointer to the first element of the array
 * @start: Starting index
 * @end: Ending index
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *build_avl(avl_t *parent, int *array, int start, int end)
{
	avl_t *root;
	int mid;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	root = binary_tree_node(parent, array[mid]);
	if (!root)
		return (NULL);

	root->left = build_avl(root, array, start, mid - 1);
	root->right = build_avl(root, array, mid + 1, end);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);

	return (build_avl(NULL, array, 0, (int)size - 1));
}
