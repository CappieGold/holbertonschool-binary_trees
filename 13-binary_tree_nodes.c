#include "binary_trees.h"
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
