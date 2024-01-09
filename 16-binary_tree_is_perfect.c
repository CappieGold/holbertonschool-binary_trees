#include "binary_trees.h"

/**
 * binary_tree_size - Helper function to measure the size of a binary tree
 * @tree: binary tree
 * Return: something
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);
	size_t size = binary_tree_size(tree);

	if (left_height != right_height)
	{
		return (0);
	}

	size_t expected_size = (1 << (left_height + 1)) - 1;

	return (size == expected_size);
}

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of a binary tree, 0 if tree is null
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
		return (0);

	else
	{
		height_left = binary_tree_height(tree->left);
		height_right = binary_tree_height(tree->right);

		if (height_left > height_right)
			return (height_left + 1);
		else
			return (height_right + 1);
	}
}
