#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: tree
 * Return: depth of a node in the binary tree
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *current_node = tree;
	size_t tree_depth = 0;

	if (tree == NULL)
		return (0);

	while (current_node->parent != NULL)
	{
		current_node = current_node->parent;
		tree_depth += 1;
	}

	return (tree_depth);
}
