#include "binary_trees.h"
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	else if (tree->left && tree->right)
	{
		if ((!(tree->left->left) && !(tree->left->right)) &&
			(!(tree->right->left) && !(tree->right->right)))
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	else if (!(tree->parent))
		return (1);

	return (0);
}
