#include "binary_trees.h"

/**
 * count_h_nodes - Counts the number of nodes in a tree
 * @tree: Pointer to the root node
 * Return: Number of nodes
 */
size_t count_h_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + count_h_nodes(tree->left) + count_h_nodes(tree->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *array;
	size_t i, count;

	if (!heap || !size)
		return (NULL);

	count = count_h_nodes(heap);
	*size = count;

	array = malloc(count * sizeof(int));
	if (!array)
		return (NULL);

	for (i = 0; i < count; i++)
		array[i] = heap_extract(&heap);

	return (array);
}
