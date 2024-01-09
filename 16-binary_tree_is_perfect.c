#include "binary_trees.h"
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

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
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

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 *
 * @tree: a pointer to the root node of the tree to count the number of nodes
 *
 * Return: If tree is NULL return 0, else return node count.
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes_left = 0;
	size_t nodes_right = 0;

	if (tree == NULL)
		return (0);

	nodes_left = binary_tree_nodes(tree->left);
	nodes_right = binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		return (nodes_left + nodes_right + 1);
	else
		return (nodes_left + nodes_right);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 0 iftree is NULL or not perfect, otherwise 1
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, node_count, max_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	node_count = binary_tree_nodes(tree);

	max_nodes = (1 << height) - 1;

	return (node_count == max_nodes);
}
