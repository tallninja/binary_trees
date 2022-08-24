#include "binary_trees.h"

/**
 * tree_depth - claculates the depth of a binary tree
 * @tree: binaryb tree
 * Return: depth of the binary tree
 */

int tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree != NULL)
	{
		depth += 1;
		tree = tree->left;
	}

	return (depth);
}

/**
 * tree_is_perfect - chacks if binary tree is perfect
 * @tree: binary tree
 * @depth: depth of the binary tree
 * @level: level
 * Return: 1 if binary tree is perfect, 0 otherwise
 */

int tree_is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == (level + 1))
			return (1);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	level += 1;

	return (tree_is_perfect(tree->left, depth, level) &&
		tree_is_perfect(tree->right, depth, level));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: binary tree
 * Return: 1 if binary tree is perfect, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth = tree_depth(tree);

	if (tree == NULL)
		return (0);

	return (tree_is_perfect(tree, depth, 0));
}
