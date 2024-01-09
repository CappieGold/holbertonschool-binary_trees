#include "binary_trees.h"

/**
 * binary_tree_size - Write a function that measures the size of a binary tree
 * @tree: the binary tree
 * Return: If tree is NULL, the function must return 0
 *         otherwise return depth of the tree
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	else
		return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}
