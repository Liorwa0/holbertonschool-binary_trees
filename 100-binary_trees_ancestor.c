#include "binary_trees.h"

/**
 * node_depth - Measures the depth of a node in a binary tree
 * @node: Pointer to the node to measure the depth
 *
 * Return: Depth of the node, or 0 if node is NULL
 */
static size_t node_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node && node->parent)
	{
		depth++;
		node = node->parent;
	}
	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth1, depth2;
	const binary_tree_t *p1 = first;
	const binary_tree_t *p2 = second;

	if (first == NULL || second == NULL)
		return (NULL);

	depth1 = node_depth(first);
	depth2 = node_depth(second);

	while (depth1 > depth2)
	{
		p1 = p1->parent;
		depth1--;
	}

	while (depth2 > depth1)
	{
		p2 = p2->parent;
		depth2--;
	}

	while (p1 && p2)
	{
		if (p1 == p2)
			return ((binary_tree_t *)p1);
		p1 = p1->parent;
		p2 = p2->parent;
	}

	return (NULL);
}
