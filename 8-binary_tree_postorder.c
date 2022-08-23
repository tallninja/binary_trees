#include "binary_trees.h"

/**
 * binary_tree_postorder - goes through a binary
 * tree using post-order traversal
 * @tree: binary tree
 * @func: pointer to a function to call for each node
 * Return: nothing
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	if (tree->left != NULL)
		binary_tree_postorder(tree->left, func);

	if (tree->right != NULL)
		binary_tree_postorder(tree->right, func);

	func(tree->n);
}
