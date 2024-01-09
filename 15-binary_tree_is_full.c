#include "binary_trees.h"

/**
 * binary_tree_is_full - Write a function that checks if a binary tree is full
 * @tree: binary tree
 * Return: If tree is NULL, your function must return 0
 *         1 if tree is full
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
