#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: the height of a binary tree, 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	if (tree == NULL)
		return (0);

	height_left = binary_tree_height(tree->left);
	height_right = binary_tree_height(tree->right);

	if (height_left > height_right)
		return (height_left + 1);
	else
		return (height_right + 1);
}

/**
 * binary_tree_size - Helper function to measure the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size.
 * Return: the size of a binary tree, 0 if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check for completeness
 * @index: index assigned to the current node
 * @number_nodes: total number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(const binary_tree_t *tree, int index, int number_nodes)
{
	if (tree == NULL)
		return (1);
	if (index >= number_nodes)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, number_nodes) &&
			is_complete(tree->right, 2 * index + 2, number_nodes));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t number_nodes = binary_tree_size(tree);
	size_t height = binary_tree_height(tree);
	size_t expected_nodes = (1 << height) - 1;

	if (expected_nodes == number_nodes)
		return (is_complete(tree, 0, number_nodes));
	return (0);
}
