#include "binary_trees.h"

/**
 * tree_height - recursively calculates the height of a binary tree
 * @tree: binary tree
 * Return: height of the binary tree
 */

size_t tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree == NULL) /* base case */
		return (0);

	l_height = tree_height(tree->left) + 1;
	r_height = tree_height(tree->right) + 1;

	if (r_height > l_height)
		return (r_height);

	return (l_height);
}

/**
 * binary_tree_height - calculates the height of a binary tree
 * @tree: binary tree
 * Return: height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	return (tree_height(tree) - 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: binary tree
 * Return: balance factor of the binary tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_balance = 0, r_balance = 0;
	int balance_factor = 0;

	if (tree == NULL)
		return (0);

	l_balance = binary_tree_height(tree->left);
	r_balance = binary_tree_height(tree->right);
	balance_factor = l_balance - r_balance;

	return (balance_factor);
}
