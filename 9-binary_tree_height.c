#include "binary_trees.h"

/**
 * get_tree_height - recursively calculates the tree height
 * @tree: tree
 * Return: height of the binary tree
 */

size_t get_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree == NULL) /* base case */
		return (0);

	l_height = get_tree_height(tree->left) + 1;
	r_height = get_tree_height(tree->right) + 1;

	if (l_height > r_height)
		return (l_height);

	else
		return (r_height);

}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: binary tree
 * Return: height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t tree_height = 0;

	if (tree == NULL)
		return (0);

	tree_height = get_tree_height(tree) - 1;

	return (tree_height);
}
