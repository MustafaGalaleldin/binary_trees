#include "binary_trees.h"
/**
 * detect_leaf - goes through a binary tree -preorder- and count leaves number
 * @tree: a pointer to the root node of the tree to traverse
 * @p: a pointer
*/
void detect_leaf(const binary_tree_t *tree, size_t *p)
{
	if (tree && p)
	{
		if (!tree->left && !tree->right)
			(*p)++;
		detect_leaf(tree->left, p);
		detect_leaf(tree->right, p);
	}
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: leaves number
*/
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves_number = 0;

	if (tree)
		detect_leaf(tree, &leaves_number);
	return (leaves_number);
}
