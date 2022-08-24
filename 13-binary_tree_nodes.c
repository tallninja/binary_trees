#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: binary tree
 * Return: number of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t no_of_nodes = 0, l_nodes = 0, r_nodes = 0;
	if (tree == NULL)
		return (0);

	if (tree->right != NULL || tree->left != NULL)
	{
		l_nodes = binary_tree_nodes(tree->left);
		r_nodes = binary_tree_nodes(tree->right);
		no_of_nodes = l_nodes + r_nodes + 1;
	}

	return no_of_nodes;
}
